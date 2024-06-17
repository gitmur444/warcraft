#pragma once

#include "command.h"
#include <string>
#include <memory>

class MarchCommand : public Command {
public:
    MarchCommand(int id, int targetX, int targetY);
    void Execute(Game& game) override;
    static std::unique_ptr<Command> Parse(const std::string& command);

    static const std::string COMMAND;

private:
    int id;
    int targetX;
    int targetY;
};
