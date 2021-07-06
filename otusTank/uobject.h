#pragma once

#include <map>;
#include <any>;

class UObject
{
public:
    std::any& getObj(std::string key); // должен возвращать ссылку на объект, может выбросить исключение
    void setObj(std::string key, std::any ptr);
    std::map<std::string, std::any> m_uobj;
};
