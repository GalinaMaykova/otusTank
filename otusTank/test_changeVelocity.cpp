#include <map>
#include <any>
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"
#include "rotate.h"
#include "movableAdapter.h"
#include "moveCommand.h"
#include "gmock\gmock.h"
#include "changeVelocityCommand.h"
#include "rotateMacro—ommand.h"

TEST(TANK_test, test_ChangeVelocityCommand)
{
    UObject tank;

    std::vector<int> v(2);
    v[0] = 4;
    v[1] = 6;
    myVector vel(v);
    tank.setObj("Velocity", vel);
    int avel = 30;
    tank.setObj("AngularVelocity", avel);

    ChangeVelocityCommand ChangeVelCmd(tank);
    ChangeVelCmd.execute();
    myVector newVelocity = std::any_cast<myVector>(tank.getObj("Velocity"));

    ASSERT_EQ(0, newVelocity.m_body[0]);
    ASSERT_EQ(7, newVelocity.m_body[1]);

}

TEST(TANK_test, test_ChangeVelocityCommandRepeat)
{
    UObject tank;

    std::vector<int> v(2);
    v[0] = 2;
    v[1] = 0;
    myVector vel(v);
    tank.setObj("Velocity", vel);
    int avel = 45;
    tank.setObj("AngularVelocity", avel);

    ChangeVelocityCommand ChangeVelCmd(tank);

    for (int i = 1; i < 10; ++i)
    {
        ChangeVelCmd.execute();
        vel = std::any_cast<myVector>(tank.getObj("Velocity"));
        std::cout << i << "_newVelocity_x = " << vel.m_body[0] << std::endl;
        std::cout << i << "_newVelocity_y = " << vel.m_body[1] << std::endl;
    }

    ASSERT_EQ(1, vel.m_body[0]);
    ASSERT_EQ(1, vel.m_body[1]);
}


TEST(TANK_test, test_RotateWithChangeVelocity)
{

    UObject tank;

    std::vector<int> v(2);
    v[0] = 4;
    v[1] = 6;
    myVector vel(v);
    tank.setObj("Velocity", vel);
    int avel = 30;
    tank.setObj("AngularVelocity", avel);
    int dir = 0;
    tank.setObj("Direction", dir);

    RotateMacro—ommand RMC(tank);
    RMC.execute();
    myVector newVelocity = std::any_cast<myVector>(tank.getObj("Velocity"));
    int newDerection = std::any_cast<int>(tank.getObj("Direction"));

    ASSERT_EQ(0, newVelocity.m_body[0]);
    ASSERT_EQ(7, newVelocity.m_body[1]);
    ASSERT_EQ(30, newDerection);
}
