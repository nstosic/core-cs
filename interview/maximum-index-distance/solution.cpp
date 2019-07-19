#include <stdio.h>

unsigned int MaximumIndexDistance(int* a, unsigned int n) {
    if (n == 0) {
        return 0;
    }
    unsigned int left_index = 0;
    unsigned int right_index = n - 1;
    unsigned int diff = 0;
    while (left_index <= right_index) {
        right_index = n - 1;
        while (a[left_index] > a[right_index] && left_index <= right_index) {
            right_index--;
        }
        if (right_index - left_index > diff) {
            diff = right_index - left_index;
        }
        left_index++;
    }
    return diff;
}