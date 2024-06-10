#include "game.h"
#include "warrior.h"
#include "archer.h"
#include <iostream>

Game::Game() : tick_(0) {}

void Game::createMap(int width, int height) {
    map_ = Map(width, height);
    events_.emplace_back("[" + std::to_string(tick_) + "] MAP_CREATED width=" + std::to_string(width) + " height=" + std::to_string(height));
}

void Game::spawnWarrior(int id, int x, int y, int hp, int strength) {
    auto warrior = std::make_shared<Warrior>(id, x, y, hp, strength);
    units_[id] = warrior;
    map_.setCell(x, y, id);
    events_.emplace_back("[" + std::to_string(tick_) + "] UNIT_SPAWNED unitId=" + std::to_string(id) + " unitType=Warrior x=" + std::to_string(x) + " y=" + std::to_string(y));
}

void Game::spawnArcher(int id, int x, int y, int hp, int strength, int range, int agility) {
    auto archer = std::make_shared<Archer>(id, x, y, hp, strength, range, agility);
    units_[id] = archer;
    map_.setCell(x, y, id);
    events_.emplace_back("[" + std::to_string(tick_) + "] UNIT_SPAWNED unitId=" + std::to_string(id) + " unitType=Archer x=" + std::to_string(x) + " y=" + std::to_string(y));
}

void Game::march(int unitId, int targetX, int targetY) {
    auto unit = units_[unitId];
    // Add logic to move the unit towards targetX, targetY
    events_.emplace_back("[" + std::to_string(tick_) + "] MARCH_STARTED unitId=" + std::to_string(unitId) + " x=" + std::to_string(unit->getX()) + " y=" + std::to_string(unit->getY()) + " targetX=" + std::to_string(targetX) + " targetY=" + std::to_string(targetY));
}

void Game::wait(int ticks) {
    for (int i = 0; i < ticks; ++i) {
        processTick();
    }
}

void Game::run() {
    while (true) {
        processTick();
        // Add logic to determine when to stop the simulation
    }
}

void Game::processTick() {
    tick_++;
    // Process each unit's action
    for (auto& [id, unit] : units_) {
        if (unit->getHp() > 0) {
            // Add logic for unit actions
        }
    }
    // Output events
    for (const auto& event : events_) {
        std::cout << event << std::endl;
    }
    events_.clear();
}
