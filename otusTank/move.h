//#pragma once
//#include "pch.h"

#ifndef MOVE_H
#define MOVE_H

#include "myVector.h"
#include "uobject.h"

class IMovable
{
public:
    virtual myVector getPosition() = 0;
    virtual void setPosition(myVector newPos) = 0;

    virtual myVector getVelocity() = 0;
    virtual ~IMovable() { std::cout << "IMovableDestructor" << std::endl; };
};

class MovableAdapter : public IMovable
{
public:

    MovableAdapter(UObject obj) :m_obj(obj)
    {}

    myVector getPosition()
    {
        return *((myVector*)m_obj.getObj("Position"));
    }

    void setPosition(myVector value)
    {
        *((myVector*)m_obj.getObj("Position")) = value;
    }
    myVector getVelocity()
    {
        return *((myVector*)m_obj.getObj("Velosity"));
    }

private:
        UObject m_obj;
};

class MoveCommand : public Command
{
public:
    MoveCommand(IMovable& movable) : m_movable(movable)
    {}

    void execute()
    {
        myVector temp = m_movable.getPosition() + m_movable.getVelocity();
        m_movable.setPosition(temp);
    }

private:
    IMovable& m_movable;
};
#endif // MOVE_H
