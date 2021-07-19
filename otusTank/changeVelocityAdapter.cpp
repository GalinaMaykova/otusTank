
#include "changeVelocityAdapter.h"


ChangeVelocityAdapter::ChangeVelocityAdapter(UObject& obj) : m_obj(obj) {}
void ChangeVelocityAdapter::setVelocity(myVector velosity)
{
    m_obj.getObj("Velocity") = velosity;
}

