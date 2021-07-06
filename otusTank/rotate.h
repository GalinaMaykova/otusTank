#pragma once

#include <iostream>
#include "myVector.h"
#include "uobject.h"
#include "command.h"

class IRotable
{
public:
    virtual int  getDirection() = 0;
    virtual void setDirection(int newPos) = 0;

    virtual int  getAngularVelocity() = 0;
  //  virtual int  getMaxDirections() = 0; // max_direction ���� ����� ����� 360, ���� ��������� ��� ������ �� �����, �� ����� ������ ������ � execute.
                                           // �.� �������� max_direction ������������ ��������� � 45, ����� ��� �������� �� 50 �������� ����� 
                                           // ����� ���� ������� �������� �� 5 ��������. � ������� ������ ���� �������� �������� ��������� ��������� � �������� ���������.
    virtual ~IRotable() { /*std::cout << "IRotableDestructor" << std::endl;*/ };
};
