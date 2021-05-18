
#include <iostream>
#include "command.h"
#include "move.h"
#include "myVector.h"
#include "uobject.h"

int main()
{
    std::vector<int> p(2);
    p[0] = 2;
    p[1] = 7; //{2, 7}
    myVector pos(p);
    std::vector<int> v(2);
    v[0] = 1;
    v[1] = 4;
    myVector vel(v);
    UObject tank;
    tank.setObj("Position", &pos);
    tank.setObj("Velosity", &vel);

    MovableAdapter mAdapter(tank);
    MoveCommand moveCmd(mAdapter);

 //   MoveCommand moveCmd1(MovableAdapter(tank));


    std::vector<Command*> cmds;
    cmds.push_back(&moveCmd);
   // cmds.push_back(&moveCmd1); 

    for (int i = 0; i < cmds.size(); ++i)
    {
        cmds[0]->execute();
    }
    
    std::cout << "x-coordinata: " << (*(myVector*)(tank.getObj("Position"))).m_body[0] << std::endl;
    std::cout << "y-coordinata: " << (*(myVector*)(tank.getObj("Position"))).m_body[1] << std::endl;
    int x;
    std::cin >> x;
}