#include "ArrayUniqueReverser.h"
#include <iostream>
#include <unordered_set>

void ArrayUniqueReverser::Transform(const std::vector<int>& input)
{
}

void ArrayUniqueReverser::TransformAll(const std::vector<std::vector<int>>& arrays)
{
    std::unordered_set<int> unique;

    for (const std::vector<int>& array : arrays)
    {
        for (int num : array)
        {
            unique.insert(num);
        }
    }

    std::vector<int> result(unique.begin(), unique.end());

    SortDescending(result);

    std::cout << "Unique reverse: ";

    for (int num : result)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}

void ArrayUniqueReverser::SortDescending(std::vector<int>& data)
{
    int n = static_cast<int>(data.size());
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (data[j] < data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
