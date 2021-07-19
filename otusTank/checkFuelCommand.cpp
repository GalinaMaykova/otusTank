
#include "checkFuelCommand.h"
#include "movableAdapter.h"
#include "burnFuelAdapter.h"
#include "myException.h"


CheckFuelCommand::CheckFuelCommand(UObject& obj) : m_obj(obj) {}

void CheckFuelCommand::execute()
{
    MovableAdapter mAdapter(m_obj);
    int sumSpeed = 0;
    for (int v : mAdapter.getVelocity().m_body)
    {
        sumSpeed += std::abs(v);
    }

    BurnFuelAdapter bA(m_obj);
    if (sumSpeed * bA.getFuelSpend() > bA.getFuel())
    {
        throw CommandException("Low fuel");
    }
}
