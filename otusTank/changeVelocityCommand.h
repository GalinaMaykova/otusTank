#pragma once
#include "command.h"
#include "uobject.h"

class ChangeVelocityCommand : public Command
{
public:
    ChangeVelocityCommand(UObject& obj);
    void execute();
    
private:
    UObject& m_obj;
};
