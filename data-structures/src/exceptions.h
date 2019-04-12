#ifndef DATA_STRUCTURE_EXCEPTIONS_H
#define DATA_STRUCTURE_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class HeapEmptyException: public std::runtime_error {
public:
    HeapEmptyException(const char* message) : std::runtime_error(message) {}
    HeapEmptyException(std::string message) : std::runtime_error(message) {}
};

class ElementNotFoundException: public std::exception {};

#endif