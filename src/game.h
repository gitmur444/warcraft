#pragma once
#include "map.h"
#include "unit.h"
#include <vector>
#include <memory>
#include <unordered_map>

class Game {
public:
    Game();
    void createMap(int width, int height);
    void spawnWarrior(int id, int x, int y, int hp, int strength);
    void spawnArcher(int id, int x, int y, int hp, int strength, int range, int agility);
    void march(int unitId, int targetX, int targetY);
    void wait(int ticks);
    void run();

private:
    Map map_;
    std::unordered_map<int, std::shared_ptr<Unit>> units_;
    std::vector<std::string> events_;
    int tick_;

    void processTick();
};
