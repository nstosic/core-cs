#ifndef ALGORITHM_EXCEPTIONS_H
#define ALGORITHM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidInfixExpression: public std::runtime_error {
public:
    InvalidInfixExpression(const char* message) : std::runtime_error(message) {}
    InvalidInfixExpression(std::string message) : std::runtime_error(message) {}
};

class IllegalArgumentException: public std::runtime_error {
public:
    IllegalArgumentException(const char* message) : std::runtime_error(message) {}
    IllegalArgumentException(std::string message) : std::runtime_error(message) {}
};

#endif