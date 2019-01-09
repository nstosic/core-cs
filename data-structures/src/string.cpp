#include "string.h"
#include <stdio.h>

String::String() {
    this->buffer = new char[255];
    this->count = 0;
}

String::~String() {
    delete this->buffer;
}

int String::length() {
    return this->count;
}

void String::print() {
    int index = 0;
    while(buffer[index] != '\0') {
        printf("%c", buffer[index]);
    }
}