#pragma once

#include <string>
#include <memory>

class Command;

class CommandParser {
public:
    std::unique_ptr<Command> Parse(const std::string& command);
};
