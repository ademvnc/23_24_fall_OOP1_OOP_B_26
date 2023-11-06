#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * @brief Class for reading input from a file.
 */

class FileReader {
public:
    /**
     * @brief Construct a new FileReader object.
     *
     * @param filename The name of the file to read from.
     */
    FileReader(const std::string& filename) : filename(filename) {}

    /**
     * @brief Read the input from the file.
     *
     * @param numbers The numbers read from the file.
     * @param operations The operations read from the file.
     * @param operands The operands read from the file.
     * @return true if the input was read successfully, false otherwise.
     */

    bool readInput(std::vector<std::string>& numbers, std::vector<char>& operations, std::vector<std::pair<int, int>>& operands) {
        std::ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return false;
        }

        int numberCount, digitCount;
        inputFile >> numberCount;
        numbers.resize(numberCount);
        for (int i = 0; i < numberCount; ++i) {
            inputFile >> digitCount;
            numbers[i] = readLargeNumber(digitCount, inputFile);
        }

        char operation;
        int operand1, operand2;
        while (inputFile >> operation >> operand1 >> operand2) {
            operations.push_back(operation);
            operands.emplace_back(operand1, operand2);
        }

        inputFile.close();
        return true;
    }

private:

    /**
     * @brief Read a large number from the input file.
     *
     * @param digitCount The number of digits in the number.
     * @param inputFile The input file stream.
     * @return The large number as a string.
     */
    std::string readLargeNumber(int digitCount, std::ifstream& inputFile) {
        std::string numberStr;
        numberStr.reserve(digitCount);
        for (int i = 0; i < digitCount; ++i) {
            char digit;
            inputFile >> digit;
            numberStr.push_back(digit);
        }
        return numberStr;
    }

    std::string filename; ///< The name of the file to read from.
};