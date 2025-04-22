#pragma once

#include "ArrayTransformer.h"

class ArrayIntersection : public ArrayTransformer
{
public:
	ArrayIntersection() = default;

	virtual ~ArrayIntersection() {};

	void Transform(const std::vector<int>& input) override;

	void TransformAll(const std::vector<std::vector<int>>& arrays) override;

	bool SupportsTransformAll() const override { return true; }

private:
    std::vector<int> IntersectTwo(const std::vector<int>& a, const std::vector<int>& b);
};
