#include "create_map_command.h"
#include "game.h"
#include <sstream>

const std::string CreateMapCommand::COMMAND = "CREATE_MAP";

CreateMapCommand::CreateMapCommand(int width, int height) : width(width), height(height) {}

void CreateMapCommand::Execute(Game& game) {
    game.CreateMap(width, height);
}

std::unique_ptr<Command> CreateMapCommand::Parse(const std::string& command) {
    std::istringstream ss(command);
    std::string cmd;
    ss >> cmd;
    int width, height;
    ss >> width >> height;
    return std::make_unique<CreateMapCommand>(width, height);
}
