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