
#include "runner.h"

#include <iostream>
#include "gmock\gmock.h"


int main(int argc, char** argv)
{
    testing::InitGoogleMock(&argc, argv);
    RUN_ALL_TESTS();

    int x;
    std::cin >> x;
}