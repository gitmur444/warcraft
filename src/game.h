#pragma once

#include "map.h"
#include "unit.h"
#include <vector>
#include <memory>
#include <string>

class Game {
public:
    Game();
    void LoadScenario(const std::string& filename);
    void Run();
    
private:
    void ProcessCommand(const std::string& command);
    void PrintEvent(const std::string& event);

    std::unique_ptr<Map> map;
    std::vector<std::unique_ptr<Unit>> units;
    int current_tick;
};
