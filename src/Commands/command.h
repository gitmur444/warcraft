#pragma once

class Game;

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute(Game& game) = 0;
};
