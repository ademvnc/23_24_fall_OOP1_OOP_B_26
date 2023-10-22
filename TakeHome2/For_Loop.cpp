/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-for-loop/problem
 * @file For_Loop.cpp
 * @brief This program reads two integers from the user and prints the English representation and parity of each number.
 * @details The program reads two integers from the user and prints the English representation and parity of each number.
 * The program uses a for loop to iterate through the range of numbers and print the corresponding English representation and parity of each number.
 * @return 0 on successful execution.
 * @author ademvnc 
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the fourth question of the HackerRank C++ Basic Certification Test.
 */
//! [includes]
#include <iostream>
#include <cstdio>
using namespace std;

//! [main]
int main() {
    //! [declarations]
    int a, b; ///< Variables to store the range of numbers.

    //!Read the range of numbers from the user
    cin >> a;
    cin >> b;

    //!Iterate through the range and print the English representation and parity of each number
    //! [statements]
    for (int i = a; i <= b; i++) {
        if (i == 1) {
            cout << "one\n";
        } else if (i == 2) {
            cout << "two\n";
        } else if (i == 3) {
            cout << "three\n";
        } else if (i == 4) {
            cout << "four\n";
        } else if (i == 5) {
            cout << "five\n";
        } else if (i == 6) {
            cout << "six\n";
        } else if (i == 7) {
            cout << "seven\n";
        } else if (i == 8) {
            cout << "eight\n";
        } else if (i == 9) {
            cout << "nine\n";
        } else {
            if (i % 2 == 0) {
                cout << "even\n";
            } else {
                cout << "odd\n";
            }
        }
    }

    //!Return 0 to indicate successful execution
    return 0;
    //! [end]
}
