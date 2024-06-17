#include "spawn_unit_command.h"
#include "game.h"
#include <sstream>

const std::string SpawnUnitCommand::COMMAND_WARRIOR = "SPAWN_WARRIOR";
const std::string SpawnUnitCommand::COMMAND_ARCHER = "SPAWN_ARCHER";

SpawnUnitCommand::SpawnUnitCommand(const std::string& unitType, int id, int x, int y, int hp, int strength, int range, int agility)
    : unitType(unitType), id(id), x(x), y(y), hp(hp), strength(strength), range(range), agility(agility) {}

void SpawnUnitCommand::Execute(Game& game) {
    game.SpawnUnit(unitType, id, x, y, hp, strength, range, agility);
}

std::unique_ptr<Command> SpawnUnitCommand::Parse(const std::string& command) {
    std::istringstream ss(command);
    std::string cmd, unitType;
    ss >> cmd;
    int id, x, y, hp, strength, range = 0, agility = 0;
    ss >> id >> x >> y >> hp >> strength;
    if (cmd == COMMAND_ARCHER) {
        ss >> range >> agility;
        unitType = "Archer";
    } else {
        unitType = "Warrior";
    }
    return std::make_unique<SpawnUnitCommand>(unitType, id, x, y, hp, strength, range, agility);
}
