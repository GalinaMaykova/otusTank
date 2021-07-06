#pragma once

//#include "myVector.h"
//#include "uobject.h"
#include "move.h"
//#include <iostream>

class MovableAdapter : public IMovable
{
public:

    MovableAdapter(UObject& obj);

    myVector getPosition();
    void setPosition(myVector value);
    myVector getVelocity();

private:
    UObject& m_obj;
};