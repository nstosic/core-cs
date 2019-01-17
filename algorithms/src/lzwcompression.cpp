#include <unordered_map>
#include <string>
#include <vector>

#define DICTIONARY_LIMIT 1024

namespace lzw {
    std::unordered_map<std::string, int> DefaultCompressionDictionary() {
        std::unordered_map<std::string, int> dictionary;
        for (int i = 0; i < 256; i++) {
            dictionary[std::string(1, i)] = i;
        }
        return dictionary;
    }

    std::unordered_map<int, std::string> DefaultDecompressionDictionary() {
        std::unordered_map<int, std::string> dictionary;
        for (int i = 0; i < 256; i++) {
            dictionary[i] = std::string(1, i);
        }
        return dictionary;
    }

    int CompressionStep(std::string input, std::unordered_map<std::string, int> &current_dictionary) {
        if (current_dictionary.find(input) == current_dictionary.end()) {
            current_dictionary[input] = (int)current_dictionary.size() - 1;
            return current_dictionary[input.substr(0, input.size() - 1)];
        }
        return -1;
    }

    std::vector<int> Compress(std::string input, std::unordered_map<std::string, int> dictionary_to_use = DefaultCompressionDictionary()) {
        std::vector<int> output_vector;
        std::string current_symbol;
        int output_code;
        for(std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
            current_symbol = current_symbol + *it;
            output_code = CompressionStep(current_symbol, dictionary_to_use);
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

    std::string DecompressionStep(int code, std::string previously_decoded, std::unordered_map<int, std::string> &current_dictionary) {
        std::string new_dictionary_entry;
        if (current_dictionary.find(code) != current_dictionary.end()) {
            new_dictionary_entry = previously_decoded;
            new_dictionary_entry = new_dictionary_entry + current_dictionary[code][0];
            current_dictionary[(int)current_dictionary.size()] = new_dictionary_entry;
        } else {
            new_dictionary_entry = previously_decoded + previously_decoded[0];
            current_dictionary[(int)current_dictionary.size()] = new_dictionary_entry;
        }
        return current_dictionary[code];
    }

    std::string Decompress(std::vector<int> compressed_code, std::unordered_map<int, std::string> dictionary_to_use = DefaultDecompressionDictionary()) {
        if (compressed_code.empty()) {
            return std::string("");
        }
        unsigned int i = 1;
        std::string output = dictionary_to_use[compressed_code[0]];
        std::string previously_decoded = output;
        while (i < compressed_code.size()) {
            previously_decoded = DecompressionStep(compressed_code[i], previously_decoded, dictionary_to_use);
            output = output + previously_decoded;
            i++;
        }
        return output;
    }
}