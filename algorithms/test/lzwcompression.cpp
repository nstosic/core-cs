#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "../src/lzwcompression.h"

TEST(Lzw_Suite, Lzw_CompressEmptyInput) {
    // Setup
    std::string input = "";
    
    // Execution
    std::vector<int> output = lzw::Compress(input);

    ASSERT_TRUE(output.empty());
}

TEST(Lzw_Suite, Lzw_CompressOutputsCorrectCode) {
    // Setup
    std::string input = "LALAA";
    std::vector<int> expected_output = {76, 65, 256, 65};

    // Execution
    std::vector<int> output = lzw::Compress(input);

    // Verification
    for (unsigned int i = 0; i < (unsigned int)output.size(); i++) {
        ASSERT_EQ(expected_output[i], output[i]);
    }
}

TEST(Lzw_Suite, Lzw_CompressionStepAddsToDictionaryIfSymbolIsNotAlreadyContained) {
    // Setup
    std::string input = "LA";
    std::unordered_map<std::string, int> mocked_dictionary;
    mocked_dictionary[std::string("L")] = 0;
    mocked_dictionary[std::string("A")] = 1;

    // Execution
    lzw::CompressionStep(input, mocked_dictionary);

    // Verification
    ASSERT_TRUE(mocked_dictionary.find(std::string("LA")) != mocked_dictionary.end());
}

TEST(Lzw_Suite, Lw_DecompressEmptyInput) {
    // Setup
    std::vector<int> input;
    std::string expected_output = "";

    // Execution
    std::string output = lzw::Decompress(input);

    // Verification
    ASSERT_EQ(expected_output, output);
}

TEST(Lzw_Suite, Lzw_DecompressOutputsCorrectString) {
    // Setup
    std::vector<int> input = {76, 65, 256, 65};
    std::string expected_output = "LALAA";

    // Execution
    std::string output = lzw::Decompress(input);

    // Verification
    ASSERT_EQ(expected_output, output);
}

TEST(Lzw_Suite, Lzw_DecompressionStepAddsCorrectValueToDictionaryWhenCodeIsMatched) {
    // Setup
    int code = 0;
    std::unordered_map<int, std::string> dictionary_to_use;
    dictionary_to_use[0] = std::string("b");

    // Execution
    lzw::DecompressionStep(code, std::string("a"), dictionary_to_use);

    // Verification
    ASSERT_EQ(std::string("ab"), dictionary_to_use[1]);
}

TEST(Lzw_Suite, Lzw_DecompressionStepAddsCorrectValueToDictionaryWhenCodeIsNotMatched) {
    // Setup
    int code = 1;
    std::unordered_map<int, std::string> dictionary_to_use;
    dictionary_to_use[0] = std::string("ab");

    // Execution
    lzw::DecompressionStep(code, std::string("a"), dictionary_to_use);

    // Verification
    ASSERT_EQ(std::string("aa"), dictionary_to_use[1]);
}

TEST(Lzw_Suite, Lzw_CompressionIsLossless) {
    // Setup
    std::string arbitrary_input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";

    // Execution
    std::vector<int> compressed_output = lzw::Compress(arbitrary_input);
    std::string decompressed_output = lzw::Decompress(compressed_output);

    // Verification
    ASSERT_EQ(arbitrary_input, decompressed_output);
}