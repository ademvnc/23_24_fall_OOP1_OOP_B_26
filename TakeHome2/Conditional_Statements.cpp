/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem
 * @file Conditional_Statements.cpp
 * @brief This program reads an integer from the user and prints its English representation.
 * @details The program reads an integer from the user and prints its English representation. If the integer is greater than 9, it prints "Greater than 9". 
 * The program uses conditional statements to check the value of the input integer and print the corresponding English representation.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the third question of the HackerRank C++ Basic Certification Test.
 */
//! [includes]
#include <bits/stdc++.h>
#include <iostream>
#include <limits>
using namespace std;

//! [main]
int main() {
    //! [declarations]
    int n;  ///< Variable to store the input number.
    
    
    //! [input]
    cin >> n; //! Read the input number from the user
    
    //! [ignore]
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //! Clear the input buffer
    
   //! [statements]
    if (n == 1)  //! Check the value of n and print the corresponding English representation 
    {
        cout << "one";
    } else if (n == 2) {
        cout << "two";
    } else if (n == 3) {
        cout << "three";
    } else if (n == 4) {
        cout << "four";
    } else if (n == 5) {
        cout << "five";
    } else if (n == 6) {
        cout << "six";
    } else if (n == 7) {
        cout << "seven";
    } else if (n == 8) {
        cout << "eight";
    } else if (n == 9) {
        cout << "nine";
    } else {
        cout << "Greater than 9";
    }

    //! [return]
    return 0; //! Return 0 to indicate successful execution
    //! [end]
    
}
