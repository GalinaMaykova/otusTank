
#include "burnFuelCommand.h"
#include "burnFuelAdapter.h"
#include "movableAdapter.h"


BurnFuelCommand::BurnFuelCommand(UObject& obj) : m_obj(obj) {}
void BurnFuelCommand::execute()
{
    MovableAdapter mA(m_obj);
    int sumSpeed = 0;
    for (int v : mA.getVelocity().m_body)
    {
        sumSpeed += std::abs(v);
    }
    BurnFuelAdapter bA(m_obj);
    bA.setFuel((bA.getFuel() - sumSpeed * bA.getFuelSpend()));
}