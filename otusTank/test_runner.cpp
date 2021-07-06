#include <map>;
#include <any>;
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"
#include "rotate.h"

#include "gmock\gmock.h"
#include "runner.h"
#include "myTqueue.h"


#include "windows.h"


typedef myTqueue<std::shared_ptr<Command>> queueCMD;

TEST(TANK_test, runner_test)
{
    queueCMD q;
    CommandRunner r(q);
    
    std::stringstream ss;
    ss << r.getThread().get_id();
    int myID = std::stoull(ss.str());
    ASSERT_EQ(0, myID);
    r.start();
    ss << r.getThread().get_id();
    myID = std::stoull(ss.str());
    std::cout << "ID " << myID << std::endl;
    ASSERT_NE(0, myID);
    r.hard_stop();
}


class MockCommand : public Command
{
public:
    MockCommand(int& x) : m_x(x)
    {
    }

    void execute()
    {
        m_x = m_x + 4;
    }
private:
    int& m_x;
};


class MockCommandHardStop : public Command
{
public:
    MockCommandHardStop(CommandRunner& cr) : m_cr(cr)
    {
    }

    void execute()
    {
        m_cr.hard_stop();
    }
private:
    CommandRunner& m_cr;
};


TEST(TANK_test, runner_test_hard_stop)
{
    queueCMD q;
    CommandRunner r(q);
    int testInt = 1;

    q.push(std::make_shared<MockCommand>(testInt));
    q.push(std::make_shared<MockCommandHardStop>(r));
    q.push(std::make_shared<MockCommand>(testInt));
    r.start();
    Sleep(500); // задержка пока второй поток все обработает
    ASSERT_EQ(5, testInt);
}


class MockCommandSoftStop : public Command
{
public:
    MockCommandSoftStop(CommandRunner& cr) : m_cr(cr)
    {
    }

    void execute()
    {
        m_cr.soft_stop();
    }
private:
    CommandRunner& m_cr;
};


TEST(TANK_test, runner_test_soft_stop)
{
    queueCMD q;
    CommandRunner r(q);
    int testInt = 1;

    q.push(std::make_shared<MockCommand>(testInt));
    q.push(std::make_shared<MockCommandSoftStop>(r));
    q.push(std::make_shared<MockCommand>(testInt));
    r.start();
    Sleep(500); // задержка пока второй поток все обработает
    ASSERT_EQ(9, testInt);
}

