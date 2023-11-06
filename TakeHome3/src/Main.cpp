#include "FileReader.h"
#include "Operation.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include <memory>

/**
 * @file TakeHome3.cpp
 * @brief This file contains the implementation of the TakeHome3 program.
 * @details The program reads input from a file and performs arithmetic operations on large numbers.
 * The input file contains the following data:
 * 1. The number of large numbers to read.
 * 2. The large numbers.
 * 3. The arithmetic operations to perform.
 * 4. The operands for each operation.
 * The program reads the input from the file and performs the operations on the operands.
 * The result of each operation is displayed on the console.
 * The program uses the following classes:
 * 1. FileReader: Class for reading input from a file.
 * 2. Operation: Abstract class for arithmetic operations.
 * 3. Addition: Class for addition operation.
 * 4. Subtraction: Class for subtraction operation.
 * 5. Multiplication: Class for multiplication operation.
 * @author ademvnc
 * @date 06/11/2023
 * @version 2.0
 * @note This is a TakeHome3 assignment from the course Object Oriented Programming Lab1 fall 2023.
 */
 
 

 













/**
 * @brief Main function.
 * @return 0 on successful execution, 1 on error.
 */

int main () {
    //!Create a FileReader instance for reading input from the file
    FileReader fileReader("input.txt");

    //!Vectors to store input data
    std::vector<std::string> numbers;
    std::vector<char> operations;
    std::vector<std::pair<int, int>> operands;

    //!Read input data from the file
    if (!fileReader.readInput(numbers, operations, operands)) {
        return 1; // Error reading input file
    }

    //!Perform operations and display results
    for (size_t i = 0; i < operations.size(); ++i) {
        //!Create an Operation instance based on the operation type
        Operation* operation;
        switch (operations[i]) {
            case 'A':
                operation = new Addition();
                break;
            case 'S':
                operation = new Subtraction();
                break;
            case 'M':
                operation = new Multiplication();
                break;
            default:
                std::cerr << "Invalid operation: " << operations[i] << std::endl;
                return 1;
        }

        //!Get the symbol corresponding to the operation type
        std::string operationSymbol;
        switch (operations[i]) {
            case 'A':
                operationSymbol = "+";
                break;
            case 'S':
                operationSymbol = "-";
                break;
            case 'M':
                operationSymbol = "*";
                break;
            default:
                std::cerr << "Invalid operation: " << operations[i] << std::endl;
                return 1;
        }

        //!Perform the operation and display the result
        std::string result = operation->performOperation(numbers[operands[i].first - 1], numbers[operands[i].second - 1]);

        std::cout << "The result of " << numbers[operands[i].first - 1];
        std::cout << " " << operationSymbol << " ";
        std::cout << numbers[operands[i].second - 1] << " is " << result << std::endl;

        //!Clean up dynamically allocated Operation instance
        delete operation;
    }

    return 0;
}

