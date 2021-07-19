#pragma once


#include "command.h"
#include "uobject.h"

class RotateMacro—ommand : Command
{
public:
    RotateMacro—ommand(UObject& obj);
    void execute();
   
private:
    UObject& m_obj;
};
