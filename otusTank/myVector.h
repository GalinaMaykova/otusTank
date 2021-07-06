#pragma once
#include <vector>

class myVector
{
public:

    myVector(std::vector<int> body);

    myVector operator+(const myVector& v1) const;
    std::vector<int> m_body;
};

