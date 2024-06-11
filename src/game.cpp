#include "game.h"
#include "warrior.h"
#include "archer.h"
#include "map.h"
#include <iostream>
#include <fstream>
#include <sstream>

Game::Game() : current_tick(0) {}

void Game::LoadScenario(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening scenario file: " << filename << std::endl;
        exit(1);
    }
    
    std::string line;
    while (std::getline(file, line)) {
        ProcessCommand(line);
    }
}

void Game::Run() {
    // Simulation loop
    while (true) {
        bool any_action = false;
        for (auto& unit : units) {
            if (unit->Act(*map, current_tick)) {
                any_action = true;
            }
        }
        if (!any_action) {
            break;
        }
        current_tick++;
    }
}

void Game::ProcessCommand(const std::string& command) {
    std::istringstream ss(command);
    std::string cmd;
    ss >> cmd;
    
    if (cmd == "CREATE_MAP") {
        int width, height;
        ss >> width >> height;
        map = std::make_unique<Map>(width, height);
        PrintEvent("MAP_CREATED width=" + std::to_string(width) + " height=" + std::to_string(height));
    } else if (cmd == "SPAWN_WARRIOR") {
        int id, x, y, hp, strength;
        ss >> id >> x >> y >> hp >> strength;
        auto warrior = std::make_unique<Warrior>(id, x, y, hp, strength);
        map->SetCellOccupied(x, y, true);
        map->AddUnit(warrior.get());  
        units.push_back(std::move(warrior));
        PrintEvent("UNIT_SPAWNED unitId=" + std::to_string(id) + " unitType=Warrior x=" + std::to_string(x) + " y=" + std::to_string(y));
    } else if (cmd == "SPAWN_ARCHER") {
        int id, x, y, hp, strength, range, agility;
        ss >> id >> x >> y >> hp >> strength >> range >> agility;
        auto archer = std::make_unique<Archer>(id, x, y, hp, strength, range, agility);
        map->SetCellOccupied(x, y, true);
        map->AddUnit(archer.get());  
        units.push_back(std::move(archer));
        PrintEvent("UNIT_SPAWNED unitId=" + std::to_string(id) + " unitType=Archer x=" + std::to_string(x) + " y=" + std::to_string(y));
    } else if (cmd == "MARCH") {
        int id, targetX, targetY;
        ss >> id >> targetX >> targetY;
        for (auto& unit : units) {
            if (unit->GetId() == id) {
                unit->SetTarget(targetX, targetY);
                PrintEvent("MARCH_STARTED unitId=" + std::to_string(id) + " x=" + std::to_string(unit->GetX()) + " y=" + std::to_string(unit->GetY()) + " targetX=" + std::to_string(targetX) + " targetY=" + std::to_string(targetY));
                break;
            }
        }
    } else if (cmd == "WAIT") {
        int ticks;
        ss >> ticks;
        current_tick += ticks;
    }
}

void Game::PrintEvent(const std::string& event) {
    std::cout << "[" << current_tick << "] " << event << std::endl;
}
