#include "wait_command.h"
#include "game.h"
#include <sstream>

const std::string WaitCommand::COMMAND = "WAIT";

WaitCommand::WaitCommand(int ticks) : ticks(ticks) {}

void WaitCommand::Execute(Game& game) {
    game.Wait(ticks);
}

std::unique_ptr<Command> WaitCommand::Parse(const std::string& command) {
    std::istringstream ss(command);
    std::string cmd;
    ss >> cmd;
    int ticks;
    ss >> ticks;
    return std::make_unique<WaitCommand>(ticks);
}
