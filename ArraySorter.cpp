#include "ArraySorter.h"
#include <iostream>

void ArraySorter::Transform(const std::vector<int>& input)
{
    std::vector<int> sorted = BubbleSort(input);

    for (int num : sorted)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

std::vector<int> ArraySorter::BubbleSort(const std::vector<int>& array)
{
	std::vector<int> result = array;
    int n = static_cast<int>(result.size());

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (result[j] > result[j + 1])
            {
                int temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    return result;
}
