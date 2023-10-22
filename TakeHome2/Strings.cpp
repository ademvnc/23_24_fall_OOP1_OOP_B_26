/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-strings/problem
 * @file Strings.cpp
 * @brief This program performs operations on two strings.
 * @details This program reads two strings from the user and performs the following operations:
 * 1. Print the sizes of the strings.
 * 2. Print the concatenation of the two strings.
 * 3. Swap the first characters of the strings.
 * 4. Print the modified strings after swapping.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the twelfth question of the HackerRank C++ Basic Certification Test.
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Main function to perform operations on two strings.
 * @return 0 on successful execution.
 */
int main() {
    string a, b; ///< Strings a and b to store user input.
    char t; ///< Temporary variable for swapping characters.

    //!Read two strings from the user
    cin >> a;
    cin >> b;

    //!Print the sizes of the strings
    cout << a.size() << " " << b.size();

    //!Print the concatenation of the two strings
    cout << "\n" << a + b;

    //!Swap the first characters of the strings
    t = a[0];
    a[0] = b[0];
    b[0] = t;

    //!Print the modified strings after swapping
    cout << endl << a << " " << b;

    //!Return 0 to indicate successful execution
    return 0;
}
