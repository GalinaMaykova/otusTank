#pragma once

#include "burnFuelAdapter.h"

BurnFuelAdapter::BurnFuelAdapter(UObject& obj) : m_obj(obj) {}


void BurnFuelAdapter::setFuel(int fuel)
{
    // количество топлива и его расход храним в одном объекте, тк одно без другого не бывает
    std::any_cast<std::pair<int, int>&>(m_obj.getObj("Fuel")).first = fuel;
}

int BurnFuelAdapter::getFuel()
{
    try
    {
        return std::any_cast<std::pair<int, int>>(m_obj.getObj("Fuel")).first;
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no Fuel in Object, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not info about fuel");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type Fuel in Object, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not info about fuel");
    }
}


int BurnFuelAdapter::getFuelSpend() // например два топлива на шаг
{
    try
    {
        return std::any_cast<std::pair<int, int>&>(m_obj.getObj("Fuel")).second;
    }
    catch (std::out_of_range& ex)
    {
        std::cout << "FATAL_ERR: no Fuel in Object, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not direction");
    }
    catch (std::bad_any_cast& ex)
    {
        std::cout << "FATAL_ERR: bad type Fuel in Object, ex.what() = " << ex.what() << std::endl;
        throw std::runtime_error("not direction");
    }
}
