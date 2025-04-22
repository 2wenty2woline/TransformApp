#pragma once

#include <memory>
#include <string>
#include "ArrayTransformer.h"

enum class ETransformType
{
    Print,
    Sort,
    Intersect,
    UniqueReverse,
    Unknown
};

ETransformType ParseTransformType(const std::string& input);

class TransformerFactory
{
public:
	TransformerFactory() = default;

	virtual ~TransformerFactory() {};

    std::unique_ptr<ArrayTransformer> Create(ETransformType type) const;
};

