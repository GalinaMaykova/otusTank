#pragma once

#include "changeVelocity.h"
#include "uobject.h"

class ChangeVelocityAdapter : public IChangeVelocity
{
public:
    ChangeVelocityAdapter(UObject& obj);
    void setVelocity(myVector velosity);

private:
    UObject& m_obj;
};