/**
 * @link https://www.hackerrank.com/challenges/variable-sized-arrays/problem
 * @file Veriable_Sized_Arrays.cpp
 * @brief This program reads a 2D vector and prints the corresponding element.
 * @details This program reads a 2D vector from the user and prints the corresponding element.
 * The program uses a 2D vector to store the integers.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the eighth question of the HackerRank C++ Basic Certification Test.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Main function to work with a 2D vector.
 * @return 0 on successful execution.
 */
//! [main]
int main() {
    int n, q; //! Number of rows and number of queries.
    
    //! [input]
    cin >> n; //!Read the number of rows and queries from the user
    cin >> q; //!Read the number of queries from the user

    //! [vector]
    vector<vector<int>> a(n); //! 2D vector to store integers.

    
    for (int j = 0; j < n; j++) //!Populate the 2D vector with elements 
    { 
        int s;
        cin >> s;
        for (int i = 0; i < s; i++) {
            int d;
            cin >> d;
            a[j].push_back(d);
        }
    }

    //!Process queries and print the corresponding element
    for (int j = 0; j < q; j++) {
        int k, l;
        cin >> k;
        cin >> l;
        cout << a[k][l] << endl;
    }

    //!Return 0 to indicate successful execution
    return 0;

    //! [end]
}


