
#include <map>;
#include <any>;
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"
#include "rotate.h"

#include "gmock\gmock.h"
class MockMOVE : public IMovable {
public:
    // MOCK_METHOD(myVector, getPosition, ());
    // MOCK_METHOD(void, setPosition, (myVector m));
    // MOCK_METHOD(myVector, getPosition, ());
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

TEST(test_case_name, test_name)
{     
        std::vector<int> p(2);
        p[0] = 2;
        p[1] = 7;
        myVector pos(p);
        std::vector<int> v(2);
        v[0] = 1;
        v[1] = 4;
        myVector vel(v);
        MockMOVE mock_mover(pos, vel);
        MoveCommand moveCmd(mock_mover);
        moveCmd.execute();
        ASSERT_EQ(4, mock_mover.getPosition().m_body[0]);
        ASSERT_EQ(11, mock_mover.getPosition().m_body[1]);
}
