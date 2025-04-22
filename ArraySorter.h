#pragma once

#include "ArrayTransformer.h"

class ArraySorter : public ArrayTransformer
{
public:
	ArraySorter() {};
	
	virtual ~ArraySorter() {};

	void Transform(const std::vector<int>& input) override;

	bool SupportsTransformAll() const override { return false; }

private:
	std::vector<int> BubbleSort(const std::vector<int>& array);
};
