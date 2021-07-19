#pragma once

#include "burnFuel.h"
#include "uobject.h"
#include <iostream>

class BurnFuelAdapter : public IBurnFuel
{
public:
    BurnFuelAdapter(UObject& obj);

    void setFuel(int fuel);
    int getFuel();
    int getFuelSpend(); // например два топлива на шаг

private:
    UObject& m_obj;
};

