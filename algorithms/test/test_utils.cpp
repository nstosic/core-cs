#include <cstdarg>
#include "../../data-structures/src/list.h"

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

List<int>* initializeList(const unsigned int param_count...) {
    List<int>* list = new List<int>();
    va_list args;
    va_start(args, param_count);
    for (unsigned int i = 0; i < param_count; i++) {
        list->Add(va_arg(args, int));
    }
    va_end(args);
    return list;
}