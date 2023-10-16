#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/**
 * @brief Main function that reads integers from a file and performs calculations.
 *
 * The program reads an integer count and a sequence of integers from a file named "input.txt".
 * Then calculates and prints the sum, product, average, and largest integer in the sequence.
 *
 * @return 0 if successful, 1 if there is an error opening the input file.
 */
int main() {
    //! Open the input file
    std::ifstream inputFile("input.txt");

    //! Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file. Make sure the file exists or is in the right path!" << std::endl;
        return 1;
    }

    //! Read the count of integers
    int count;
    inputFile >> count;

    //! Read the sequence of integers
    std::vector<int> integers(count);
    for (int i = 0; i < count; ++i) {
        inputFile >> integers[i];
    }

    //! Close the input file
    inputFile.close();

    //! Calculate sum, product, average, and largest
    int totalSum = 0;
    int product = 1;
    int largest = integers[0]; //! First

    for (int num : integers) {
        totalSum += num;
        product *= num;
        largest = std::max(largest, num); //! En büyük sayıyı bulmak için std::max fonksiyonunu kullanırız.
    }

    //! Calculate average
    double average = static_cast<double>(totalSum) / count;

    //! Print the results
    std::cout << "Sum is " << totalSum << std::endl;
    std::cout << "Product is " << product << std::endl;
    std::cout << "Average is " << average << std::endl;
    std::cout << "Largest is " << largest << std::endl;

    //! Return 0 to indicate successful execution
    return 0;
}
