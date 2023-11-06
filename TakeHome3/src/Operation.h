#ifndef OPERATION_H
#define OPERATION_H

#include <string>

/**
 * @brief Abstract class for arithmetic operations.
 */

class Operation {
public:

    /**
     * @brief Perform the operation on the two operands.
     *
     * @param operand1 The first operand.
     * @param operand2 The second operand.
     * @return The result of the operation.
     */
    virtual std::string performOperation(const std::string& operand1, const std::string& operand2) const = 0;
};

#endif // OPERATION_H