/**
    *@link https://www.hackerrank.com/challenges/arrays-introduction
    *@file Arrays_Introduction.cpp
    *@brief This program reads an array of integers and prints the array in reverse order. 
    *@details This program reads an array of integers from the user and prints the array in reverse order.
    *The program uses a dynamic array to store the integers.
    *@return 0 on successful execution.
    *@author ademvnc
    *@date 10/08/2021
    *@version 1.0
    *@note This program is a solution to the seventh question of the HackerRank C++ Basic Certification Test.

*/

//! [includes]
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Main function to read and reverse an array of integers.
 * @return 0 on successful execution.
 */
//! [main]
int main() {
    int N, i = 0; ///! Number of elements and loop variable.
    
    //! [input]
    std::cin >> N; //!Read the number of elements from the user
    
    //! [array]
    int *A = new int[N]; //! Dynamic array to store integers
    
    //! [read]
    while (std::cin >> A[i++]); //!Read the array elements from the user
    
    //! [print]
    while (std::cout << A[--N] << ' ' && N); //!Print the array elements in reverse order

    //! [free]
    delete[] A; //!Free the allocated memory
    
    //! [return]
    return 0; //!Return 0 to indicate successful execution

    //! [end]
}
