#pragma once

#include <vector>
#include <string>

class FileReader
{
public:
    FileReader() = default;

	std::vector<std::vector<int>> ReadArraysFromFile(const std::string& filename);

private:
    std::vector<int> ParseLine(const std::string& line);
    std::string NormalizeDelimiters(const std::string& line);
};
