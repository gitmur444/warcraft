#pragma once

#include "command.h"
#include <string>
#include <memory>

class SpawnUnitCommand : public Command {
public:
    SpawnUnitCommand(const std::string& unitType, int id, int x, int y, int hp, int strength, int range = 0, int agility = 0);
    void Execute(Game& game) override;
    static std::unique_ptr<Command> Parse(const std::string& command);

    static const std::string COMMAND_WARRIOR;
    static const std::string COMMAND_ARCHER;

private:
    std::string unitType;
    int id;
    int x;
    int y;
    int hp;
    int strength;
    int range;
    int agility;
};
