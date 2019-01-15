#ifndef LZW_H
#define LZW_H

#include <unordered_map>
#include <string>

namespace lzw {
    std::unordered_map<std::string, int> defaultDictionary();
    int compression_step(std::string input, std::unordered_map<std::string, int> &current_dictionary);
    std::vector<int> compress(std::string input, std::unordered_map<std::string, int> dictionary_to_use = defaultDictionary());
}

#endif