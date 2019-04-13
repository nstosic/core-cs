/*
    Note, this task is originally found at: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

    Also, the implemented solution in this translation unit is described here: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/

    Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct.

*/
#include "../../data-structures/src/min_heap.h"
#include "../../data-structures/src/max_heap.h"
#include "../src/exceptions.h"

int Kth_Smallest(int* array, unsigned int n, unsigned int k) {
    if (k >= n) {
        throw new IllegalArgumentException("Value of argument k must be less than the value of argument n");
    }
    MaxHeap<int> heap;
    for (unsigned int i = 0; i < n; i++) {
        if (heap.Size() < k) {
            heap.Add(array[i]);
        } else if (heap.GetTop() > array[i]) {
            heap.RemoveTop();
            heap.Add(array[i]);
        }
    }
    return heap.GetTop();
}

int Kth_Largest(int* array, unsigned int n, unsigned int k) {
    if (k >= n) {
        throw new IllegalArgumentException("Value of argument k must be less than the value of argument n");
    }
    MinHeap<int> heap;
    for (unsigned int i = 0; i < n; i++) {
        if (heap.Size() < k) {
            heap.Add(array[i]);
        } else if (heap.GetTop() < array[i]) {
            heap.RemoveTop();
            heap.Add(array[i]);
        }
    }
    return heap.GetTop();
}

int Kth_Element(int* array, unsigned int n, unsigned int k, int smallest_or_largest) {
    if (smallest_or_largest > 0) {
        return Kth_Largest(array, n, k);
    }
    return Kth_Smallest(array, n, k);
}