#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "../src/lzwcompression.h"

TEST(LZW_Suite, LZW_CompressEmptyInput) {
    // Setup
    std::string input = "";
    
    // Execution
    std::vector<int> output = lzw::compress(input);

    ASSERT_TRUE(output.empty());
}

TEST(LZW_Suite, LZW_CompressOutputsCorrectCode) {
    // Setup
    std::string input = "LALAA";
    std::vector<int> expected_output = {76, 65, 255, 65};

    // Execution
    std::vector<int> output = lzw::compress(input);

    // Verification
    for (unsigned int i = 0; i < (unsigned int)output.size(); i++) {
        ASSERT_EQ(expected_output[i], output[i]);
    }
}

TEST(LZW_Suite, LZW_CompressAddsToDictionaryIfSymbolIsNotContained) {
    // Setup
    std::string input = "LA";
    std::unordered_map<std::string, int> mocked_dictionary;
    mocked_dictionary[std::string("L")] = 1;
    mocked_dictionary[std::string("A")] = 2;

    // Execution
    std::vector<int> output = lzw::compress(input, mocked_dictionary);

    // Verification
    ASSERT_TRUE(mocked_dictionary.find(std::string("LA")) != mocked_dictionary.end());
}