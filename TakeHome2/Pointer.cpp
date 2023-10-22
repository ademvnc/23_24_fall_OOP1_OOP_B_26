
/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-pointer/problem
 * @file Pointer.cpp
 * @brief Updates the values of two integers.
 * @details This program reads two integers from the user and updates the values of the integers using a function.
 * The program uses a function to update the values of the integers.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the sixth question of the HackerRank C++ Basic Certification Test.
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 * @return Void.
 * 
 */


#include <stdio.h>
#include <iostream>
using namespace std;

//! Function to update the values of two integers

void update(int *a, int *b)  
{
    int sum = *a + *b;
    int absDifference = *a - *b > 0 ? *a - *b : -(*a - *b);
    *a = sum;
    *b = absDifference; 
}

/**
 * @brief Main function to demonstrate updating integer values.
 * @return 0 on successful execution.
 */
//! [main]
int main() {
    int a, b; //! Variables to store the integers
    int *pa = &a, *pb = &b; //! Pointers to the integers
    
    //! [input]
    scanf("%d %d", &a, &b); //!Read two integers from the user

    //! [function]
    update(pa, pb); //!Update the values of the integers using the 'update' function

    //! [output]
    printf("%d\n%d", a, b); //!Print the updated values of the integers

    //! [return]
    return 0; //!Return 0 to indicate successful execution

    //! [end]
}
