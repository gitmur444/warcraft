#include "march_command.h"
#include "game.h"
#include <sstream>

const std::string MarchCommand::COMMAND = "MARCH";

MarchCommand::MarchCommand(int id, int targetX, int targetY) : id(id), targetX(targetX), targetY(targetY) {}

void MarchCommand::Execute(Game& game) {
    game.March(id, targetX, targetY);
}

std::unique_ptr<Command> MarchCommand::Parse(const std::string& command) {
    std::istringstream ss(command);
    std::string cmd;
    ss >> cmd;
    int id, targetX, targetY;
    ss >> id >> targetX >> targetY;
    return std::make_unique<MarchCommand>(id, targetX, targetY);
}
