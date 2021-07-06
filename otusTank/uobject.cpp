#include "uobject.h";

std::any& UObject::getObj(std::string key) // ������ ���������� ������ �� ������, ����� ��������� ����������
{
    return m_uobj.at(key);
}

void UObject::setObj(std::string key, std::any ptr)
{
    m_uobj.insert(std::make_pair(key, ptr));
}

