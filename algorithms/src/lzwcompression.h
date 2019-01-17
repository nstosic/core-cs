#ifndef LZW_H
#define LZW_H

#include <unordered_map>
#include <string>

namespace lzw {
    std::unordered_map<std::string, int> DefaultCompressionDictionary();
    std::unordered_map<int, std::string> DefaultDecompressionDictionary();
    int CompressionStep(std::string input, std::unordered_map<std::string, int> &current_dictionary);
    std::vector<int> Compress(std::string input, std::unordered_map<std::string, int> dictionary_to_use = DefaultCompressionDictionary());
    std::string DecompressionStep(int code, std::string previously_decoded, std::unordered_map<int, std::string> &current_dictionary);
    std::string Decompress(std::vector<int> compressed_code, std::unordered_map<int, std::string> dictionary_to_use = DefaultDecompressionDictionary());
}

#endif