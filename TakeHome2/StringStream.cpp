/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem
 * @file StringStream.cpp
 * @brief This program reads a string of space-separated integers and prints each integer on a new line.
 * @details This program reads a string of space-separated integers from the user and prints each integer on a new line.
 * The program uses a stringstream to parse the string and store the integers in a vector.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the eleventh question of the HackerRank C++ Basic Certification Test.
 * 
 * 
 */

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

/**
 * @brief Parses a string containing space-separated integers into a vector of integers.
 * @param str Input string containing space-separated integers.
 * @return Vector of integers parsed from the input string.
 */
vector<int> parseInts(string str) {
    stringstream ss(str); 
    vector<int> result;
    char ch;
    int tmp;

    //!Parse integers from the input string
    while (ss >> tmp) {  
        result.push_back(tmp);
        ss >> ch;          
    }

    return result;
}

/**
 * @brief Main function to read a string of space-separated integers and print each integer on a new line.
 * @return 0 on successful execution.
 */
int main() {
    string str;
    
    //!Read a string of space-separated integers from the user
    cin >> str;

    //!Parse the string and store the integers in a vector
    vector<int> integers = parseInts(str);

    //!Print each integer on a new line
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    //!Return 0 to indicate successful execution
    return 0;
}
