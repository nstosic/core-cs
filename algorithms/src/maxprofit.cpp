/*
    Note, this task is originally found at: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    Say you have an array for which the i-th element is the price of a given stock on day i.

    If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

    Note that you cannot sell a stock before you buy one.
*/

#include "vector"

int MaxProfit(std::vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int minimum = prices[0];
    int maximum = 0;
    for(std::vector<int>::iterator it = ++prices.begin(); it != prices.end(); ++it) {
        if (*it - minimum > maximum) {
            maximum = *it - minimum;
        } else if (*it < minimum) {
            minimum = *it;
        }
    }
    return maximum;
}