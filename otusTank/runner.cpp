#include "runner.h"

CommandRunner::CommandRunner(queueCMD& queueCMDs) : m_queueCMDs(queueCMDs){}

CommandRunner::~CommandRunner()
{
    t.join();
}

void CommandRunner::start()
{
    t = std::thread(&CommandRunner::run, this);
}

void CommandRunner::run()
{
    while (1)
    {
        if (is_hard_stop)
        {
            is_hard_stop = false;
            return;
        }

        try
        {
            std::shared_ptr<Command> cmd;
            if (m_queueCMDs.pop(cmd)) // возврращает false, если очередь пуста
            {
                cmd->execute();
            }
            else if (is_soft_stop)
            {
                is_soft_stop = false;
                return;
            }
        }
        catch (...)
        {

        }
    }
}

void  CommandRunner::hard_stop()
{
    is_hard_stop = true;
}

void CommandRunner::soft_stop()
{
    is_soft_stop = true;
}

std::thread& CommandRunner::getThread()
{
    return t;
}


