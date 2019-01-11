#include "string.h"
#include <stdio.h>
#include <cstring>

String::String() {
    this->buffer = nullptr;
    this->count = 0L;
}

String::~String() {
    delete[] this->buffer;
}

unsigned long String::length() const {
    return this->count;
}

void String::print() const {
    int index = 0;
    while(buffer[index] != '\0') {
        printf("%c", buffer[index]);
    }
}

const char* String::unsafePointer() const {
    return this->buffer;
}

// Operator overloading
void String::operator= (const char* data) {
    delete[] this->buffer;
    count = sizeof(data);
    this->buffer = new char[count];
    memcpy(this->buffer, data, count);
}