#include "uobject.h";

std::any& UObject::getObj(std::string key) // должен возвращать ссылку на объект, может выбросить исключение
{
    return m_uobj.at(key);
}

void UObject::setObj(std::string key, std::any ptr)
{
    m_uobj.insert(std::make_pair(key, ptr));
}

