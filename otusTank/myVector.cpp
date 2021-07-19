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
                             
myVector myVector::rotate(const int angle) const
{
    std::vector<int> vec(2);
    const double angleInRadian = angle * 3.1415926535 / 180;

 
    vec[0] = static_cast<int>(round(m_body[0] * cos(angleInRadian) - m_body[1] * sin(angleInRadian)));
    vec[1] = static_cast<int>(round(m_body[0] * sin(angleInRadian) + m_body[1] * cos(angleInRadian)));
    myVector answer(vec);
    return answer;
}

