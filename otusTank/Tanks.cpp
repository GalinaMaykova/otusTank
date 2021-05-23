
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"
#include "rotate.h"
#include "gmock\gmock.h"

//
//class MockA : public IMovable
//{
//public:
//    MOCK_METHOD2(Method1, int(int a, int b));
//};




int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    RUN_ALL_TESTS();

    std::vector<int> p(2);
    p[0] = 2;
    p[1] = 7;
    myVector pos(p);
    std::vector<int> v(2);
    v[0] = 1;
    v[1] = 4;
    myVector vel(v);

    int dir = 45;
    int avel = 370;
    int maxdir = 360;
    UObject tank;
    tank.setObj("Position", pos);
    tank.setObj("Velosity", vel);
    tank.setObj("Direction", dir);
    tank.setObj("AngularValocity", avel);
    tank.setObj("MaxDirections", maxdir);

    MovableAdapter mAdapter(tank);
    MoveCommand moveCmd(mAdapter);
    RotableAdapter rAdapter(tank);
    RotateCommand rotCmd(rAdapter);

    std::vector<Command*> cmds;
    cmds.push_back(&moveCmd);
    cmds.push_back(&rotCmd);

    for (int i = 0; i < cmds.size(); ++i)
    {
        cmds[i]->execute();
    }
    
    std::cout << "x: " << std::any_cast<myVector>((tank.getObj("Position"))).m_body[0] << std::endl;
    std::cout << "y: " << std::any_cast<myVector>((tank.getObj("Position"))).m_body[1] << std::endl;
    std::cout << "angle: " << std::any_cast<int>((tank.getObj("Direction"))) << std::endl;
    int x;
    std::cin >> x;
}