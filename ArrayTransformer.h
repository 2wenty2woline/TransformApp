#pragma once

#include <vector>

class ArrayTransformer
{
public:
    virtual ~ArrayTransformer() = default;

    virtual void Transform(const std::vector<int>& input) = 0;

    virtual bool SupportsTransformAll() const = 0;

    virtual void TransformAll(const std::vector<std::vector<int>>& arrays) {};
};