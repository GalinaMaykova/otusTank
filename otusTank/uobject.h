#pragma once

#include <map>;
#include <any>;

class UObject
{
public:
    std::any& getObj(std::string key); // ������ ���������� ������ �� ������, ����� ��������� ����������
    void setObj(std::string key, std::any ptr);
    std::map<std::string, std::any> m_uobj;
};
