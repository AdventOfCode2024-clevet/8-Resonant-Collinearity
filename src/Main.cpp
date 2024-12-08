#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
        return (1);
    }

    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return (1);
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    std::map<char, std::vector<std::pair<int, int>>> antennas;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            if (lines[i][j] != '.') {
                antennas[lines[i][j]].push_back(std::make_pair(i, j));
            }
        }
    }

    std::set<std::pair<int, int>> uniqueAntinodes;

    for (auto& [freq, positions] : antennas) {
        if (positions.size() > 1) {
            for (const auto& pos : positions) {
                uniqueAntinodes.insert(pos);
            }
        }

        for (size_t i = 0; i < positions.size(); i++) {
            for (size_t j = i + 1; j < positions.size(); j++) {
                int x1 = positions[i].first;
                int y1 = positions[i].second;
                int x2 = positions[j].first;
                int y2 = positions[j].second;

                int dx = x2 - x1;
                int dy = y2 - y1;

                for (int k = 1; k <= std::max(lines.size(), lines[0].size()); k++) {
                    int x3 = x1 - k * dx;
                    int y3 = y1 - k * dy;
                    if (x3 >= 0 && x3 < lines.size() && y3 >= 0 && y3 < lines[0].size()) {
                        uniqueAntinodes.insert({x3, y3});
                    }

                    int x4 = x2 + k * dx;
                    int y4 = y2 + k * dy;
                    if (x4 >= 0 && x4 < lines.size() && y4 >= 0 && y4 < lines[0].size()) {
                        uniqueAntinodes.insert({x4, y4});
                    }
                }
            }
        }
    }

    std::cout << "Result: " << uniqueAntinodes.size() << std::endl;

    return (0);
}
