/**
 * @link https://www.hackerrank.com/challenges/cpp-input-and-output/problem
 * @file Input_and_Output.cpp
 * @brief This program reads three integers and prints their sum.
 * @details This program reads three integers from the user and prints their sum.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the second question of the HackerRank C++ Basic Certification Test.
 * 
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Main function to calculate the sum of three integers.
 * @return 0 on successful execution.
 */
int main() {
    int a, b, c; ///< Variables to store three integers.

    //!Read three integers from the user
    cin >> a >> b >> c;

    //!Calculate and print the sum of the three integers
    cout << a + b + c;

    //!Return 0 to indicate successful execution
    return 0;
}
