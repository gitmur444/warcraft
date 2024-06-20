#include "game.h"
#include "warrior.h"
#include "archer.h"
#include "map.h"
#include "Commands/command_parser.h"
#include "Commands/command.h"
#include "Events/map_created_event.h"
#include "Events/unit_spawned_event.h"
#include "Events/march_started_event.h"
#include "Events/unit_attacked_event.h"
#include "Events/unit_died_event.h"
#include "Events/unit_moved_event.h"
#include <iostream>
#include <fstream>
#include <sstream>

Game::Game() : current_tick(0), commandParser(std::make_unique<CommandParser>()) {}

void Game::LoadScenario(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening scenario file: " << filename << std::endl;
        exit(1);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        ExecuteCommand(line);
    }
}

void Game::Run() {
    while (true) {
        bool any_action = false;
        for (auto it = units.begin(); it != units.end(); ) {
            if ((*it)->Act(*map, units, current_tick)) {
                any_action = true;
            }
            // Check if the unit is dead and remove it if necessary
            if ((*it)->GetHp() <= 0) {
                it = units.erase(it);
            } else {
                ++it;
            }
        }
        if (!any_action) {
            break;
        }
        current_tick++;
    }
}

void Game::ExecuteCommand(const std::string& command) {
    auto parsedCommand = commandParser->Parse(command);
    if (parsedCommand) {
        ExecuteCommand(std::move(parsedCommand));
    }
}

void Game::ExecuteCommand(std::unique_ptr<Command> command) {
    command->Execute(*this);
}

void Game::CreateMap(int width, int height) {
    map = std::make_unique<Map>(width, height);
    eventHandler.HandleEvent(std::make_shared<MapCreatedEvent>(width, height));
}

void Game::SpawnUnit(const std::string& unitType, int id, int x, int y, int hp, int strength, int range, int agility) {
    std::unique_ptr<Unit> unit;
    if (unitType == "Warrior") {
        unit = std::make_unique<Warrior>(id, x, y, hp, strength);
    } else if (unitType == "Archer") {
        unit = std::make_unique<Archer>(id, x, y, hp, strength, range, agility);
    }
    map->SetCellOccupied(x, y, true);
    map->AddUnit(unit.get());
    units.push_back(std::move(unit));
    eventHandler.HandleEvent(std::make_shared<UnitSpawnedEvent>(id, unitType, x, y));
}

void Game::March(int id, int targetX, int targetY) {
    for (auto& unit : units) {
        if (unit->GetId() == id) {
            unit->SetTarget(targetX, targetY);
            eventHandler.HandleEvent(std::make_shared<MarchStartedEvent>(id, unit->GetX(), unit->GetY(), targetX, targetY));
            break;
        }
    }
}

void Game::Wait(int ticks) {
    current_tick += ticks;
}
