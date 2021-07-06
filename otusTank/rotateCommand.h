#pragma once
#include "rotate.h"

class RotateCommand : public Command
{
public:
    RotateCommand(IRotable& rotable);
    void execute();

private:
    IRotable& m_rotable;
};