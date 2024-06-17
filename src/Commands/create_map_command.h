#pragma once

#include "command.h"
#include <string>
#include <memory>

class CreateMapCommand : public Command {
public:
    CreateMapCommand(int width, int height);
    void Execute(Game& game) override;
    static std::unique_ptr<Command> Parse(const std::string& command);

    static const std::string COMMAND;

private:
    int width;
    int height;
};
