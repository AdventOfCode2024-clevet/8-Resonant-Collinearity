#include <stdexcept>

#include "ArgumentParser.hpp"

ResonantCollinearity::ArgumentParser::ArgumentParser(int argc, char* argv[])
{
    if (argc < 2 || argc > 3)
    {
        throw std::invalid_argument("Usage: <program> <input> [1|2]");
    }

    inputFile = argv[1];
    part = (argc == 3) ? std::stoi(argv[2]) : 1;

    if (part != 1 && part != 2)
    {
        throw std::invalid_argument("Error: part must be 1 or 2");
    }
}

const std::string &ResonantCollinearity::ArgumentParser::getInputFile() const
{
    return (inputFile);
}

int ResonantCollinearity::ArgumentParser::getPart() const
{
    return (part);
}
