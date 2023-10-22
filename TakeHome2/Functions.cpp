/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-functions/problem
 * @file Functions.cpp
 * @brief Calculates the maximum of four integers.
 * @details This program reads four integers from the user and prints the maximum of the four integers.
 * The program uses a function to calculate the maximum of four integers.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the fifth question of the HackerRank C++ Basic Certification Test.
 * @param a First integer.
 * @param b Second integer.
 * @param c Third integer.
 * @param d Fourth integer.
 * @return Maximum of the four integers.
 * 
 */

#include <iostream>
#include <cstdio>

using namespace std;

//! [function]

int max_of_four(int a, int b, int c, int d) //!Function to calculate the maximum of four integers
 {
    if (a > b && a > c && a > d) {
        return a;
    } else if (b > a && b > c && b > d) {
        return b;
    } else if (c > b && c > a && c > d) {
        return c;
    } else {
        return d;
    }
}

/**
 * @brief Main function to find and print the maximum of four integers.
 * @return 0 on successful execution.
 */

//! [main]
int main() {
    int a, b, c, d;

    //! [input]
    scanf("%d %d %d %d", &a, &b, &c, &d); //!Read four integers from the user

    //! [function]
    int ans = max_of_four(a, b, c, d); //!Calculate the maximum of four integers

    //! [output]
    printf("%d", ans); //!Print the result

    //! [return]
    return 0; //!Return 0 to indicate successful execution
    //! [end]
    
}
