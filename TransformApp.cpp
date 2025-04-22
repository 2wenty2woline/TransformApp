
#include <iostream>
#include "ArrayPrinter.h"
#include "FileReader.h"
#include "ArraySorter.h"
#include "TransformerFactory.h"
#include "ArrayIntersection.h"
#include "ArrayUniqueReverser.h"

int main()
{
    const std::string filename = "arrays.txt";

    FileReader reader;
    std::vector<std::vector<int>> arrays = reader.ReadArraysFromFile(filename);

    if (arrays.empty())
    {
        std::cerr << "Empty or not found" << std::endl;
        return 0;
    }

    std::cout << "Select action (print / sort / intersect / uniqrev) : " ;
    std::string type;
    std::cin >> type;
    std::cout << std::endl;

    ETransformType enumType = ParseTransformType(type);
    TransformerFactory factory;
    std::unique_ptr<ArrayTransformer> transformer = factory.Create(enumType);

    if (!transformer)
    {
        std::cerr << "Unknown transformer type: " << type << std::endl;
        return 0;
    }

    if (transformer->SupportsTransformAll())
    {
        transformer->TransformAll(arrays);
        return 0;
    }

    int arraySize = static_cast<int>(arrays.size());
    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << "Array " << i + 1 << ": ";
        transformer->Transform(arrays[i]);
    }

    return 0;
}
