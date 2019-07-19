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