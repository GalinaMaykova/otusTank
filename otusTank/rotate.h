#pragma once

#include <iostream>
#include "myVector.h"
#include "uobject.h"
#include "command.h"

class IRotable
{
public:
    virtual int  getDirection() = 0;
    virtual void setDirection(int newPos) = 0;

    virtual int  getAngularVelocity() = 0;
  //  virtual int  getMaxDirections() = 0; // max_direction пока пусть будет 360, если позволить его менять на любое, то нужна дргуая логика в execute.
                                           // т.к например max_direction пользователь установит в 45, тогда при повороте на 50 градусов игрок 
                                           // будет явно удивлен повороту на 5 градусов. в будущем скорре надо добавить диапазон возможных поворотов к текущему положению.
    virtual ~IRotable() { /*std::cout << "IRotableDestructor" << std::endl;*/ };
};
