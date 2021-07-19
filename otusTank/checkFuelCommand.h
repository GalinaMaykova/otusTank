#pragma once


#include "uobject.h"
#include "command.h"




class CheckFuelCommand : public Command
{
public:
    CheckFuelCommand(UObject& obj);
    void execute();

private:
    UObject& m_obj;
};