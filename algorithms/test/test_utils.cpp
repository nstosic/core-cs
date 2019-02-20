#include <cstdarg>

int* initializeArray(const unsigned int param_count...) {
    int* array = new int[param_count];
    va_list args;
    va_start(args, param_count);
    for (unsigned int i = 0; i < param_count; i++) {
        array[i] = va_arg(args, int);
    }
    va_end(args);
    return array;
}