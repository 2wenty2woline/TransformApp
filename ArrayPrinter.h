#pragma once

#include "ArrayTransformer.h"

class ArrayPrinter : public ArrayTransformer
{
public:
	ArrayPrinter() {};

	virtual ~ArrayPrinter() {};

	void Transform(const std::vector<int>& input) override;

	bool SupportsTransformAll() const override { return false; }
};
