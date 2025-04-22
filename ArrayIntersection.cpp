#include "ArrayIntersection.h"
#include <iostream>
#include <unordered_set>

void ArrayIntersection::Transform(const std::vector<int>& input)
{
}

void ArrayIntersection::TransformAll(const std::vector<std::vector<int>>& arrays)
{
	int sizeArray = static_cast<int>(arrays.size());
	
	if (sizeArray < 2)
	{
        std::cout << "Not enough arrays to intersect" << std::endl;
        return;
	}
	
	std::vector<int> result = IntersectTwo(arrays[0], arrays[1]);

	if (sizeArray >= 3)
	{
		result = IntersectTwo(result, arrays[2]);
	}

	std::cout << "Intersection: ";

	for (int num : result)
	{
        std::cout << num << " ";
	}

    std::cout << std::endl;
}

std::vector<int> ArrayIntersection::IntersectTwo(const std::vector<int>& a, const std::vector<int>& b)
{
	std::unordered_set<int> setA(a.begin(), a.end());
    std::unordered_set<int> result;

    for (int num : b)
    {
		if (setA.count(num) > 0)
		{
			result.insert(num);
		}
	}

	return std::vector<int>(result.begin(), result.end());
}
