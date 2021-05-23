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
    virtual int  getMaxDirections() = 0;
    virtual ~IRotable() { std::cout << "IRotableDestructor" << std::endl; };
};


class RotableAdapter : public IRotable
{
public:

    RotableAdapter(UObject& obj) :m_obj(obj)
    {}

    int getDirection()
    {
        // хорошо бы обернуть try/catch
        return std::any_cast<int>(m_obj.getObj("Direction"));
    }

    void setDirection(int value)
    {
        m_obj.getObj("Direction") = value;
    }
    int getAngularVelocity()
    {
        return std::any_cast<int>(m_obj.getObj("AngularValocity"));
    }
    int getMaxDirections()
    {
        return std::any_cast<int>(m_obj.getObj("MaxDirections"));
    }

private:
    UObject& m_obj;
};

class RotateCommand : public Command
{
public:
    RotateCommand(IRotable& rotable) : m_rotable(rotable)
    {}

    void execute()
    {
        int temp = (m_rotable.getDirection() + m_rotable.getAngularVelocity()) % m_rotable.getMaxDirections();
        m_rotable.setDirection(temp);
    }

private:
    IRotable& m_rotable;
};