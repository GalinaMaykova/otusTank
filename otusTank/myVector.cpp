#include "myVector.h"


myVector::myVector(std::vector<int> body) :m_body(body){}

myVector myVector::operator+(const myVector& v1) const
{
    std::vector<int> newBody(m_body.size());

    for (int i = 0; i < m_body.size(); ++i)
    {
        newBody[i] = this->m_body[i] + v1.m_body[i];
    }
    return newBody;
}

