#include "Operation.h"

/**
 * @brief Class for subtraction operation.
 */

class Subtraction : public Operation {
public:

    /**
     * @brief Perform subtraction on the two operands.
     *
     * @param operand1 The first operand.
     * @param operand2 The second operand.
     * @return The result of the subtraction.
     */
    std::string performOperation(const std::string& operand1, const std::string& operand2) const override {
        return subtractStrings(operand1, operand2);

    
    }

private:

    /**
     * @brief Subtract two large numbers represented as strings.
     *
     * @param num1 The first number.
     * @param num2 The second number.
     * @return The difference of the two numbers.
     */

   std::string subtractStrings(const std::string& num1, const std::string& num2) const {
    std::string result;
    int borrow = 0;

    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i, --j) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;

        int diff = digit1 - digit2 - borrow;

        
        if (diff < 0) {
            diff += 10;
            borrow = -2;
            
        } else {
            borrow = 0;
        }

        


        result.insert(result.begin(), diff + '0');
    }

    //!Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));

    if (result.empty()) {
        return "0";
    } else if (borrow) {
        //!If there is a borrow after subtraction, add a '-' at the beginning
        result.insert(result.begin(), '-');
    }

    return result;
}
};