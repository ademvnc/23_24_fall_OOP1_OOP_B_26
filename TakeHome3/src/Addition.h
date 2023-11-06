#ifndef ADDITION_H
#define ADDITION_H

#include "Operation.h"

/**
 * @brief Class for addition operation.
 */



class Addition : public Operation {
public:

    /**
     * @brief Perform addition on the two operands.
     *
     * @param operand1 The first operand.
     * @param operand2 The second operand.
     * @return The result of the addition.
     */

    std::string performOperation(const std::string& operand1, const std::string& operand2) const override {
        return addStrings(operand1, operand2);
    }

private:

    /**
     * @brief Add two large numbers represented as strings.
     *
     * @param num1 The first number.
     * @param num2 The second number.
     * @return The sum of the two numbers.
     */
    std::string addStrings(const std::string& num1, const std::string& num2) const {
        std::string result;
        int carry = 0;

        for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            sum %= 10;

            result.insert(result.begin(), sum + '0');
        }

        return result;
    }
};

#endif // ADDITION_H