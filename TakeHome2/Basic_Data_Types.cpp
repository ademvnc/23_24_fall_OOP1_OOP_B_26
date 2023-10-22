/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem
 * @file Basic_Data_Types.cpp
 * @brief This program reads and prints various data types.
 * @details This program reads an integer, a long integer, a character, a float, and a double from standard input and prints them to standard output.
 * The program uses scanf to read the input values and printf to print the output values.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the second question of the HackerRank C++ Basic Certification Test.
 */

//! [includes]
#include <iostream>
#include <cstdio>
using namespace std;

//! [main]
int main() {
    //! [declarations]
    int a;      ///< Integer variable
    long b;     ///< Long integer variable
    char c;     ///< Character variable
    float d;    ///< Float variable
    double e;   ///< Double variable
    
    //! [input]
    //!Reading values from standard input
    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    
    //! [output]
    //!Printing values to standard output
    printf("%d\n%ld\n%c\n%f\n%lf", a, b, c, d, e);
    
    //! [return]
    return 0;
}

//! [end]
