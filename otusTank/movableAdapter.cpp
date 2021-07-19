#include "movableAdapter.h"

MovableAdapter::MovableAdapter(UObject& obj) :m_obj(obj)
{}

myVector MovableAdapter::getPosition()
{
    try
    {
        return  std::any_cast<myVector>(m_obj.getObj("Position"));
    }
    //getObj - ����� ��������� ���������� ���������� �������, ���� ������� - ���������� �������������� �����
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no position in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type position in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
}

void MovableAdapter::setPosition(myVector value)
{
    m_obj.getObj("Position") = value;
}

myVector MovableAdapter::getVelocity()
{
    try
    {
        return std::any_cast<myVector>(m_obj.getObj("Velocity"));
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no velocity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type velocity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
}