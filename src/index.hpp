#pragma once

#include <fstream>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_set>
#include <vector>

class Index {
private:
    std::map<std::string, std::vector<int>> index_map;

public:
    void readFile(const std::string& filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        std::unordered_set<std::string> commonWords = {
            "a", "an", "and", "are", "for", "in", "is",
            "of", "on", "the", "they", "to", "you", "your", 
            "he", "she", "it", "we", "us", "them", "this", "that"
        };

        std::string word;
        int position = 0;

        while (file >> word) {
            std::string cleanedWord;

            for (char character : word) {
                if (std::isalpha(character) || character == '-') {
                    cleanedWord += std::tolower(character);
                }
            }

            if (!cleanedWord.empty() && commonWords.count(cleanedWord) == 0) {
                index_map[cleanedWord].push_back(position);
            }

            ++position;
        }
    }

    void writeIndex(const std::string& filename) const {
        std::ofstream file(filename);

        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filename);
        }

        file << "{\n";

        bool firstWord = true;
        for (const auto& pair : index_map) {
            if (!firstWord) {
                file << ",\n";
            }

            file << "  \"" << pair.first << "\": [";

            for (std::size_t i = 0; i < pair.second.size(); ++i) {
                if (i > 0) {
                    file << ", ";
                }
                file << pair.second[i];
            }

            file << "]";
            firstWord = false;
        }

        file << "\n}\n";
    }
};
