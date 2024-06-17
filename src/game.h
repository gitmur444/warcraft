#pragma once

#include "map.h"
#include "unit.h"
#include "Commands/command_parser.h"
#include "Events/event_handler.h"
#include <vector>
#include <memory>
#include <string>

class Game {
public:
    Game();
    void LoadScenario(const std::string& filename);
    void Run();
    void ExecuteCommand(const std::string& command);
    void ExecuteCommand(std::unique_ptr<Command> command);

    void CreateMap(int width, int height);
    void SpawnUnit(const std::string& unitType, int id, int x, int y, int hp, int strength, int range = 0, int agility = 0);
    void March(int id, int targetX, int targetY);
    void Wait(int ticks);

private:
    std::unique_ptr<Map> map;
    std::vector<std::unique_ptr<Unit>> units;
    int current_tick;
    std::unique_ptr<CommandParser> commandParser;
    EventHandler eventHandler;
};
