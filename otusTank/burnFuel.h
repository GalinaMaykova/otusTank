#pragma once


class IBurnFuel // ��� ���������� ����� ��� � ������
{
public:
    virtual void setFuel(int start) = 0;
    virtual int getFuel() = 0;
    virtual int getFuelSpend() = 0; // �������� ����� ������� 
    virtual ~IBurnFuel() {};
};