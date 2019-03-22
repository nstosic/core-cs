#include <string>
#include <stdexcept>
#include "../../data-structures/src/stack.h"
#include "shuntingyard.h"

#define SUPPORTED_OPERATION_COUNT 4

const char* ConvertToPostfix(const char* infix_expression) {
    const char* supported_operators[] = {"+", "-", "*", "/"};
    std::string input(infix_expression);
    std::string output;
    std::string number("");
    Stack<const char*> operator_stack;
    for (std::string::iterator it = input.begin(); it != input.end(); it = ++it) {
        if (isdigit(*it)) {
            number += *it;
        } else {
            if (!number.empty()) {
                output += number;
                output += " ";
                number.clear();
            }
            if (isspace(*it) || ',' == *it) {
                // Ignore
            } else if ('(' == *it) {
                std::string *op_str = new std::string(1, *it);
                operator_stack.Push(op_str->c_str());
            } else if (')' == *it) {
                bool matching_parenthesis_missing = true;
                while (matching_parenthesis_missing && !operator_stack.IsEmpty()) {
                    const char* op_str = operator_stack.Pop();
                    if ('(' == op_str[0]) {
                        matching_parenthesis_missing = false;
                    } else {
                        output += op_str;
                        output += " ";
                    }
                }
                if (matching_parenthesis_missing) {
                    throw InvalidInfixExpression("Invalid expression given as input, parenthesis mismatch");
                }
            } else {
                // Assume that the current token is a function or operation designator
                bool operator_supported = false;
                for (unsigned int i = 0; i < SUPPORTED_OPERATION_COUNT && !operator_supported; i++) {
                    operator_supported = *it == supported_operators[i][0];
                }
                std::string *op_str = new std::string(1, *it);
                if (!operator_supported) {
                    throw InvalidInfixExpression("Invalid expression given as input, unsupported operation: " + *op_str);
                } else {
                    operator_stack.Push(op_str->c_str());
                }
            }
        }
    }
    if (!number.empty()) {
        output += number;
        output += " ";
        number.clear();
    }
    while (!operator_stack.IsEmpty()) {
        output += operator_stack.Pop();
        output += " ";
    }
    if (!output.empty()) {
        // Remove extra whitespace at the end
        output.erase(output.size() - 1, 1);
    }
    return output.c_str();
}