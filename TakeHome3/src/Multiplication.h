#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "Operation.h"

/**
 * @brief Class for multiplication operation.
 */
class Multiplication : public Operation {
public:
    /**
     * @brief Perform multiplication on the two operands.
     *
     * @param operand1 The first operand.
     * @param operand2 The second operand.
     * @return The result of the multiplication.
     */
     std::string performOperation(const std::string& operand1, const std::string& operand2) const override;


private:
    /**
     * @brief Multiply two large numbers represented as strings.
     *
     * @param num1 The first number.
     * @param num2 The second number.
     * @return The product of the two numbers.
     */
    std::string multiplyStrings(const std::string& num1, const std::string& num2) const;
};

inline std::string Multiplication::performOperation(const std::string& operand1, const std::string& operand2) const {
    return multiplyStrings(operand1, operand2);
}

// Add the missing declaration for multiplyStrings
inline std::string Multiplication::multiplyStrings(const std::string& num1, const std::string& num2) const {
    int m = num1.size();
    int n = num2.size();
    std::vector<int> result(m + n, 0);

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    std::string resultStr;
    for (int digit : result) {
        resultStr.push_back(digit + '0');
    }

    // Remove leading zeros
    resultStr.erase(0, resultStr.find_first_not_of('0'));

    return resultStr.empty() ? "0" : resultStr;
}

#endif // MULTIPLICATION_H
