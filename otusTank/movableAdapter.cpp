#include "movableAdapter.h"

MovableAdapter::MovableAdapter(UObject& obj) :m_obj(obj)
{}

myVector MovableAdapter::getPosition()
{
    try
    {
        return  std::any_cast<myVector>(m_obj.getObj("Position"));
    }
    //getObj - может выбросить исключение отсутствие объекта, каст вектора - исключение несоответствия типов
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
        return std::any_cast<myVector>(m_obj.getObj("Velosity"));
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no velosity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type velosity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not position");
    }
}