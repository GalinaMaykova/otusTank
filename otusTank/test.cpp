
#include <map>;
#include <any>;
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"
#include "rotate.h"

#include "gmock\gmock.h"
class MockMOVE : public IMovable 
{
public:
    MockMOVE(myVector& position, myVector& velocity) : m_position(position), m_velocity(velocity) {}
    myVector getPosition()
    {
        return m_position;
    }
    void setPosition(myVector value)
    {
        m_position = value;
    }
    myVector getVelocity()
    {
        return m_velocity;
    }
    myVector& m_position;
    myVector& m_velocity;
};

TEST(TANK_test, test_change_position)
{
    std::vector<int> p(2);
    p[0] = 12;
    p[1] = 5;
    myVector pos(p);
    std::vector<int> v(2);
    v[0] = -7;
    v[1] = 3;
    myVector vel(v);
    MockMOVE mock_mover(pos, vel);
    MoveCommand moveCmd(mock_mover);
    moveCmd.execute();
    ASSERT_EQ(5, mock_mover.getPosition().m_body[0]);
    ASSERT_EQ(8, mock_mover.getPosition().m_body[1]);
}

//
//class MockMOVEnotPos : public MockMOVE
//{
//public:
//    MockMOVEnotPos(myVector& position, myVector& velocity) : MockMOVE(position, velocity)
//    {}
//    myVector getPosition()
//    {
//        throw std::runtime_error("not position");
//    }
//};

TEST(TANK_test, test_no_position)
//как с помощью мок-объекта проверить реальную функциональность MovableAdapter и бросания им исключения?
{     
        std::vector<int> v(2);
        v[0] = -7;
        v[1] = 3;
        myVector vel(v);
        UObject tank;
        tank.setObj("Velosity", vel);
        MovableAdapter mAdapter(tank);
        MoveCommand moveCmd(mAdapter);
        ASSERT_THROW(moveCmd.execute(), std::runtime_error);

}

