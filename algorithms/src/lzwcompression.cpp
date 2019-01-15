#include <unordered_map>
#include <string>
#include <vector>

#define DICTIONARY_LIMIT 1024

namespace lzw {
    std::unordered_map<std::string, int> defaultDictionary() {
        std::unordered_map<std::string, int> dictionary;
        for (int i = 0; i < 256; i++) {
            dictionary[std::string(1, i)] = i;
        }
        return dictionary;
    }

    int compression_step(std::string input, std::unordered_map<std::string, int> &current_dictionary) {
        if (current_dictionary.find(input) == current_dictionary.end()) {
            current_dictionary[input] = (int)current_dictionary.size();
            return current_dictionary[input.substr(0, input.size() - 1)];
        }
        return -1;
    }

    std::vector<int> compress(std::string input, std::unordered_map<std::string, int> dictionary_to_use = defaultDictionary()) {
        std::vector<int> output_vector;
        std::string current_symbol;
        int output_code;
        for(std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
            current_symbol = current_symbol + *it;
            output_code = compression_step(current_symbol, dictionary_to_use);
            if (output_code >= 0) {
                current_symbol.erase(0, current_symbol.size() - 1);
                output_vector.push_back(output_code);
            }
        }
        // Check if the last symbol needs to be compressed
        if (!current_symbol.empty()) {
            output_vector.push_back(dictionary_to_use[current_symbol]);
        }
        return output_vector;
    }
}