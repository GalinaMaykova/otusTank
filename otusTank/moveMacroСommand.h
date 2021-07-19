#pragma once


#include "command.h"
#include "uobject.h"

class MoveMacro—ommand : Command
{
public:
    MoveMacro—ommand(UObject& obj);
    void execute();
  
private:
    UObject& m_obj;
};
