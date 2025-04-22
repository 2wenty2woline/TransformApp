#pragma once

#include "ArrayTransformer.h"

class ArrayUniqueReverser : public ArrayTransformer
{
public:
	ArrayUniqueReverser() = default;

	virtual ~ArrayUniqueReverser() {};

	void Transform(const std::vector<int>& input) override;

	void TransformAll(const std::vector<std::vector<int>>& arrays) override;

	bool SupportsTransformAll() const override { return true; }

private:
	void SortDescending(std::vector<int>& data);
};
