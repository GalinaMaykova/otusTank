#pragma once
#include "command.h"

class Macro—ommand : Command
{
public:
    Macro—ommand(std::vector<Command*>& cmds) : m_cmds(cmds) {}
    void execute()
    {
        for (Command* cmd : m_cmds)
        {
            cmd->execute();
        }
    }
private:
    std::vector<Command*>& m_cmds;
};
