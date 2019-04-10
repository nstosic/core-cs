#include <gtest/gtest.h>
#include <vector>

extern int MaxProfit(std::vector<int>& prices);

TEST(MaxProfitSuite, MaxProfitForEmptySeriesReturnsZero) {
    // Setup
    std::vector<int> prices;

    // Execution
    int result = MaxProfit(prices);

    // Verification
    ASSERT_EQ(0, result);
}

TEST(MaxProfitSuite, MaxProfitForSeriesWithSingleElementReturnsZero) {
    // Setup
    std::vector<int> prices;
    prices.push_back(33);

    // Execution
    int result = MaxProfit(prices);

    // Verification
    ASSERT_EQ(0, result);
}

TEST(MaxProfitSuite, MaxProfitReturnsCorrectValue) {
    // Setup
    std::vector<int> prices;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    // Execution
    int result = MaxProfit(prices);

    // Verification
    ASSERT_EQ(5, result);
}

TEST(MaxProfitSuite, MaxProfitReturnsZeroIfNoProfitCanBeMade) {
    // Setup
    std::vector<int> prices;
    prices.push_back(7);
    prices.push_back(6);
    prices.push_back(4);
    prices.push_back(3);
    prices.push_back(1);

    // Execution
    int result = MaxProfit(prices);

    // Verification
    ASSERT_EQ(0, result);
}