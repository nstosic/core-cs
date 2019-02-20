void radixsort_step_countsort(int* array, unsigned int number_of_elements, int order_of_digit) {
    int* sorted_array = new int[number_of_elements];
    int count[10] = {0};
    for (unsigned int i = 0; i < number_of_elements; i++) {
        count[(array[i] / order_of_digit) % 10]++;
    }
    for (unsigned int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }
    for (unsigned int i = number_of_elements - 1; i > 0; i--) {
        sorted_array[count[(array[i] / order_of_digit) % 10] - 1] = array[i];
        count[(array[i] / order_of_digit) % 10]--;
    }
    sorted_array[count[(array[0] / order_of_digit) % 10] - 1] = array[0];
    for (unsigned int i = 0; i < number_of_elements; i++) {
        array[i] = sorted_array[i];
    }
}

void radixsort(int* array, unsigned int number_of_elements) {
    if (number_of_elements == 0) {
        return;
    }
    int max = array[0];
    for (unsigned int i = 1; i < number_of_elements; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    for (int order_of_digit = 1; max / order_of_digit > 0; order_of_digit = order_of_digit * 10) {
        radixsort_step_countsort(array, number_of_elements, order_of_digit);
    }
}