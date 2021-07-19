#pragma once


class IBurnFuel // его реализация будет ужо в тестах
{
public:
    virtual void setFuel(int start) = 0;
    virtual int getFuel() = 0;
    virtual int getFuelSpend() = 0; // скорость траты топлива 
    virtual ~IBurnFuel() {};
};