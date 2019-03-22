#include <gtest/gtest.h>
#include "../src/shuntingyard.h"

extern const char* ConvertToPostfix(const char* infix_expression);

TEST(ShuntingYardSuite, ShuntingYardReturnsEmptyOutputForEmptyInput) {
    // Setup
    const char* input = "";

    // Execution
    const char* output = ConvertToPostfix(input);

    // Verification
    ASSERT_STREQ("", output);
}

TEST(ShuntingYardSuite, ShuntingYardOutputForSimpleExpressionIsCorrect) {
    // Setup
    const char* input = "3 + 4";

    // Execution
    const char* output = ConvertToPostfix(input);

    // Verification
    ASSERT_STREQ("3 4 +", output);
}

TEST(ShuntingYardSuite, ShuntingYardOutputForSimpleExpressionWithParenthesisIsCorrect) {
    // Setup
    const char* input = "3 + (3 - 6) * 3";

    // Execution
    const char* output = ConvertToPostfix(input);

    // Verification
    ASSERT_STREQ("3 3 6 - 3 * +", output);
}

TEST(ShuntingYardSuite, ShuntingYardThrowsAnExceptionIfInputHasMismatchingParenthesis) {
    // Setup
    const char* input = "3 + 3 - 2 * (4 - 6)) + 1";

    // Execution
    ASSERT_THROW(ConvertToPostfix(input), InvalidInfixExpression);
}

TEST(ShuntingYardSuite, ShuntingYardThrowsAnExceptionIfInputHasAnInvalidOperator) {
    // Setup
    const char* input = "3 + 3 - 2 s (4 - 6)) + 1";

    // Execution
    ASSERT_THROW(ConvertToPostfix(input), InvalidInfixExpression);
}