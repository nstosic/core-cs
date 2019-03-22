#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H

#include <exception>

class InvalidInfixExpression: public std::runtime_error {
public:
    InvalidInfixExpression(const char* message) : std::runtime_error(message) {}
    InvalidInfixExpression(std::string message) : std::runtime_error(message) {}
};

#endif