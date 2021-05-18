//#pragma once
//#include "pch.h"

#ifndef UOBJECT_H
#define UOBJECT_H

#include <map>;

class UObject
{
public:
    void* getObj(std::string key) 
    {
        return m_uobj.at(key);
    }
    void setObj(std::string key, void* ptr)
    {
        m_uobj.insert(std::make_pair(key, ptr));
    }
    std::map<std::string, void*> m_uobj;
};

#endif //UOBJECT_H
