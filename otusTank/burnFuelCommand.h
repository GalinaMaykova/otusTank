#pragma once

#include "uobject.h"
#include "command.h"

class BurnFuelCommand : public Command
{
public:
    BurnFuelCommand(UObject& obj);
    void execute();
private:
    UObject& m_obj;
};
