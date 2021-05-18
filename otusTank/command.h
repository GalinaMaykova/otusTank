//#pragma once
//#include "pch.h"


#ifndef COMMAND_H
#define COMMAND_H

#include <vector>;

class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() { std::cout << "CommandDestructor" << std::endl; };
};



class MacroCommand : public Command
{
public:

    MacroCommand(std::vector<Command*> cmds): m_cmds(cmds)
    {}

    void execute()
    {
        for(int i = 0; i < m_cmds.size(); ++i)
        {
            m_cmds[i]->execute();
        }
    }

private:
    std::vector<Command*> m_cmds;
};
#endif // COMMAND_H