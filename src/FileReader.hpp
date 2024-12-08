#pragma once

#ifndef FILEREADER_HPP
    #define FILEREADER_HPP

    #include <fstream>
    #include <string>
    #include <vector>

    namespace ResonantCollinearity
    {
        class FileReader
        {
            public:
                explicit FileReader(const std::string &fileName);
                ~FileReader() = default;

                std::vector<std::string> readLines();

            private:
                std::ifstream input;
        };
    }

#endif /* FILEREADER_HPP */
