#include "quicksort.h"
#include <stdexcept>

inline void swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

// @Hoare partition

unsigned int hoare_partition(int* array_pointer, unsigned int start_index, unsigned int end_index) {
    int pivot_value = array_pointer[(end_index + start_index) / 2];
    unsigned int smaller_index = start_index, bigger_index = end_index;
    while (smaller_index < bigger_index) {
        while(array_pointer[smaller_index] < pivot_value) {
            smaller_index++;
        }
        while(array_pointer[bigger_index] > pivot_value) {
            bigger_index--;
        }
        if (smaller_index < bigger_index) {
            swap(array_pointer[smaller_index], array_pointer[bigger_index]);
        } else {
            return bigger_index;
        }
        smaller_index++;
        bigger_index--;
    }
    return bigger_index;
}

void quicksort_hoare_step(int* array_pointer, unsigned int start_index, unsigned int end_index) {
    if (start_index < end_index) {
        unsigned int pivot_index = hoare_partition(array_pointer, start_index, end_index);
        quicksort_hoare_step(array_pointer, start_index, pivot_index);
        quicksort_hoare_step(array_pointer, pivot_index + 1, end_index);
    }
}

void quicksort_hoare(int* array_pointer, unsigned int number_of_elements) {
    quicksort_hoare_step(array_pointer, 0, number_of_elements - 1);
}

// @Lomuto partition

unsigned int lomuto_partition(int* array_pointer, unsigned int start_index, unsigned int end_index) {
    int pivot_value = array_pointer[end_index];
    unsigned int correct_pivot_index = start_index, index = start_index;
    while (index < end_index) {
        if (array_pointer[index] <= pivot_value) {
            swap(array_pointer[correct_pivot_index], array_pointer[index]);
            correct_pivot_index++;
        }
        index++;
    }
    swap(array_pointer[correct_pivot_index], array_pointer[end_index]);
    return correct_pivot_index;
}

void quicksort_lomuto_step(int* array_pointer, unsigned int start_index, unsigned int end_index) {
    if (start_index < end_index) {
        // Preprocess the array using the "median of three" rules, per Robert Sedgewick recommendation
        unsigned int middle_index = (start_index + end_index) / 2;
        if (array_pointer[middle_index] < array_pointer[start_index]) {
            swap(array_pointer[middle_index], array_pointer[start_index]);
        }
        if (array_pointer[end_index] < array_pointer[start_index]) {
            swap(array_pointer[end_index], array_pointer[start_index]);
        }
        if (array_pointer[end_index] < array_pointer[middle_index]) {
            swap(array_pointer[end_index], array_pointer[middle_index]);
        }
        unsigned int pivot_index = lomuto_partition(array_pointer, start_index, end_index);
        quicksort_lomuto_step(array_pointer, start_index, pivot_index - 1);
        quicksort_lomuto_step(array_pointer, pivot_index + 1, end_index);
    }
}

void quicksort_lomuto(int* array_pointer, unsigned int number_of_elements) {
    quicksort_lomuto_step(array_pointer, 0, number_of_elements - 1);
}

// @External quicksort call

void quicksort(int* array_pointer, unsigned int number_of_elements, int quicksort_scheme = QS_HOARE) {
    if (number_of_elements == 0) {
        return;
    }
    if (quicksort_scheme == QS_HOARE) {
        quicksort_hoare(array_pointer, number_of_elements);
    } else if (quicksort_scheme == QS_LOMUTO) {
        quicksort_lomuto(array_pointer, number_of_elements);
    } else {
        std::runtime_error("Illegal quicksort_scheme encountered");
    }
}