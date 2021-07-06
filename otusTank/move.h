#pragma once

#include "myVector.h"
#include "uobject.h"
#include "command.h"
#include <iostream>

class IMovable
{
public:
    virtual myVector getPosition() = 0;
    virtual void setPosition(myVector newPos) = 0;

    virtual myVector getVelocity() = 0;
    virtual ~IMovable() { /*std::cout << "IMovableDestructor" << std::endl;*/ };
};
