#pragma once

#include <iostream>

class CommandException : public std::exception
{
public:
    CommandException(const char* ex) : std::exception(ex)
    {
        std::cout << "CommandException: " << std::endl;
    }
};
