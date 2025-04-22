#include "FileReader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

std::vector<std::vector<int>> FileReader::ReadArraysFromFile(const std::string& filename)
{
    std::vector<std::vector<int>> arrays;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return arrays;
    }

    std::string line;
    while (std::getline(file, line))
    {
        arrays.push_back(ParseLine(line));
    }

    return arrays;
}

std::vector<int> FileReader::ParseLine(const std::string& line)
{
    std::vector<int> numbers;
    std::string cleaned = NormalizeDelimiters(line);
    std::istringstream stream(cleaned);
    std::string token;

    while (stream >> token)
    {
        try
        {
            numbers.push_back(std::stoi(token));
        }
        catch (...)
        {
            std::cerr << "Invalid number: " << token << std::endl;
        }
    }

    return numbers;
}

std::string FileReader::NormalizeDelimiters(const std::string& line)
{
    std::string cleaned = line;
    for (char& ch : cleaned)
    {
        if (ch == ',' || std::isspace(static_cast<unsigned char>(ch)))
        {
            ch = ' ';
        }
    }
    return cleaned;
}
