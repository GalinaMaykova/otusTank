#include "rotableAdapter.h"


RotableAdapter::RotableAdapter(UObject& obj) :m_obj(obj){}

int RotableAdapter::getDirection()
{
    try
    {
        return std::any_cast<int>(m_obj.getObj("Direction"));
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no direction in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not direction");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type direction in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not direction");
    }
}

void RotableAdapter::setDirection(int value)
{
    m_obj.getObj("Direction") = value;
}

int RotableAdapter::getAngularVelocity()
{
    try
    {
        return std::any_cast<int>(m_obj.getObj("AngularVelocity"));
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no angularVelocity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not angularValocity");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type angularVelocity in MovableObject, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not angularValocity");
    }
}