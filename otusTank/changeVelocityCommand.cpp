
#include "changeVelocityCommand.h"
#include "rotableAdapter.h"
#include "movableAdapter.h"
#include "changeVelocityAdapter.h"

ChangeVelocityCommand::ChangeVelocityCommand(UObject& obj) : m_obj(obj) {}
void ChangeVelocityCommand::execute()
{
    RotableAdapter rA(m_obj);
    MovableAdapter mA(m_obj);
    ChangeVelocityAdapter cVA(m_obj);

    try
    {
        myVector velocity = mA.getVelocity();
        cVA.setVelocity(velocity.rotate(rA.getAngularVelocity()));
    }
    catch (std::exception& ex)
    {
        return;
    }
}
