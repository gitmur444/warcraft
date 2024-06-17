#pragma once

#include "command.h"
#include <string>
#include <memory>

class WaitCommand : public Command {
public:
    WaitCommand(int ticks);
    void Execute(Game& game) override;
    static std::unique_ptr<Command> Parse(const std::string& command);

    static const std::string COMMAND;

private:
    int ticks;
};
