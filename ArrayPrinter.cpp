#include "ArrayPrinter.h"
#include <iostream>

void ArrayPrinter::Transform(const std::vector<int>& input)
{
    for (int num : input)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}
