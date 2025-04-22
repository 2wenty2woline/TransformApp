#include "TransformerFactory.h"
#include "ArrayPrinter.h"
#include "ArraySorter.h"
#include "ArrayIntersection.h"
#include "ArrayUniqueReverser.h"

ETransformType ParseTransformType(const std::string& input)
{
    if (input == "print") return ETransformType::Print;
    if (input == "sort") return ETransformType::Sort;
    if (input == "intersect") return ETransformType::Intersect;
    if (input == "uniqrev") return ETransformType::UniqueReverse;

    return ETransformType::Unknown;
}

std::unique_ptr<ArrayTransformer> TransformerFactory::Create(ETransformType type) const
{
    switch (type)
    {
        case ETransformType::Print: return std::make_unique<ArrayPrinter>();
        case ETransformType::Sort: return std::make_unique<ArraySorter>();
        case ETransformType::Intersect: return std::make_unique<ArrayIntersection>();
        case ETransformType::UniqueReverse: return std::make_unique<ArrayUniqueReverser>();
        default: return nullptr;
    }
}
