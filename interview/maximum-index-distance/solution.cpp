#include <stdio.h>

int MaximumIndexDistanceSolution(int* a, unsigned int n) {
    unsigned int left_index = 0;
    unsigned int right_index = n - 1;
    int diff = 0;
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