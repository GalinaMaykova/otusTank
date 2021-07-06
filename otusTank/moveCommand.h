#pragma once
#include "move.h"

class MoveCommand : public Command
{
public:
    MoveCommand(IMovable& movable);
    void execute();

private:
    IMovable& m_movable;
};