#pragma once
#include "rotate.h"

class RotableAdapter : public IRotable
{
public:

    RotableAdapter(UObject& obj);

    int getDirection();
    void setDirection(int value);
    int getAngularVelocity();

private:
    UObject& m_obj;
};