#pragma 
#include "myTqueue.h"
#include "command.h" 
#include <thread>

typedef myTqueue<std::shared_ptr<Command>> queueCMD;

class CommandRunner
{
public:
    CommandRunner(queueCMD& queueCMDs);
    ~CommandRunner();   

    void start();
    void run();
    void hard_stop();
    void soft_stop();
    std::thread& getThread();

private:
    std::thread t;
    queueCMD& m_queueCMDs;  
    bool is_hard_stop = false;
    bool is_soft_stop = false;
};