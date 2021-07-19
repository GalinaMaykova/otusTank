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


#include "checkFuelCommand.h"
#include "BurnFuelCommand.h"
#include "MoveMacro�ommand.h"
#include "myException.h"


TEST(TANK_test, test_CheckFuelPositiv)
{
    UObject tank;
    tank.setObj("Fuel", std::make_pair(20, 2));
    std::vector<int> v(2);
    v[0] = -7;
    v[1] = 3;
    myVector vel(v);
    tank.setObj("Velocity", vel);

    CheckFuelCommand chFuelCmd(tank);
    ASSERT_NO_THROW(chFuelCmd.execute(), CommandException);
}


TEST(TANK_test, test_CheckFuelNegative)
{
    UObject tank;
    tank.setObj("Fuel", std::make_pair(12, 2));
    std::vector<int> v(2);
    v[0] = -7;
    v[1] = 3;
    myVector vel(v);
    tank.setObj("Velocity", vel);

    CheckFuelCommand chFuelCmd(tank);
    ASSERT_THROW(chFuelCmd.execute(), CommandException);
}



TEST(TANK_test, test_BurnFuelComamnd1)
{
    UObject tank;
    tank.setObj("Fuel", std::make_pair(23, 2));
    std::vector<int> v(2);
    v[0] = 7;
    v[1] = 3;
    myVector vel(v);
    tank.setObj("Velocity", vel);

    BurnFuelCommand bFuelCmd(tank);
    bFuelCmd.execute();
    std::pair<int, int> myPair = std::any_cast<std::pair<int, int>>(tank.getObj("Fuel"));
    ASSERT_EQ(3, myPair.first);
}


TEST(TANK_test, test_BurnFuelComamnd2)
{
    UObject tank;
    tank.setObj("Fuel", std::make_pair(14, 1));
    std::vector<int> v(2);
    v[0] = -7;
    v[1] = -7;
    myVector vel(v);
    tank.setObj("Velocity", vel);

    BurnFuelCommand bFuelCmd(tank);
    bFuelCmd.execute();
    std::pair<int, int> myPair = std::any_cast<std::pair<int, int>>(tank.getObj("Fuel"));
    ASSERT_EQ(0, myPair.first);
}



TEST(TANK_test, test_MoveWithFuel)
{
    UObject tank;

    tank.setObj("Fuel", std::make_pair(107, 2)); // 107 ������� ����, 2 ������� �� ���.
    std::vector<int> p(2);
    p[0] = 12;
    p[1] = 6;
    myVector pos(p);
    tank.setObj("Position", pos);
    std::vector<int> v(2);
    v[0] = -7;
    v[1] = 3;
    myVector vel(v);
    tank.setObj("Velocity", vel);

    MoveMacro�ommand MMC(tank);
    MMC.execute();

    //��� ��� ��� ����� ���������� � �������
    std::pair<int, int> myPair = std::any_cast<std::pair<int, int>>(tank.getObj("Fuel"));
    myVector newPosition = std::any_cast<myVector>(tank.getObj("Position"));
    

    ASSERT_EQ(87, myPair.first); // 107 - 20 (��� 20��, ��� ���������� ���������� (7+3) � ������� - 2 ������� ������� � ������� ����������
    ASSERT_EQ(5, newPosition.m_body[0]);
    ASSERT_EQ(9, newPosition.m_body[1]);
}
