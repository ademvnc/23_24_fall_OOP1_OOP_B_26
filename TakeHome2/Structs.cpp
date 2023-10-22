/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-struct/problem
 * @file Structs.cpp
 * @brief This program demonstrates the use of structs.
 * @details This program reads student information from the user and prints the information to standard output.
 * The program uses a struct to store the student information.
 * @return 0 on successful execution.
 * @author ademvnc
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the thirteenth question of the HackerRank C++ Basic Certification Test.
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @brief Represents a student with age, first name, last name, and standard information.
 */
struct Student {
    int age; ///< Age of the student.
    string first_name; ///< First name of the student.
    string last_name; ///< Last name of the student.
    int standard; ///< Standard of the student.

    /**
     * @brief Default constructor for the Student struct.
     */
    Student() : age(0), standard(0) {}

    /**
     * @brief Constructor for the Student struct with specified values.
     * @param age Age of the student.
     * @param first_name First name of the student.
     * @param last_name Last name of the student.
     * @param standard Standard of the student.
     */
    Student(int age, const string& first_name, const string& last_name, int standard)
        : age(age), first_name(first_name), last_name(last_name), standard(standard) {}
};

/**
 * @brief Main function to demonstrate the use of the Student struct.
 * @return 0 on successful execution.
 */
int main() {
    Student st; ///< Instance of the Student struct.

    //!Read student information from the user
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;

    //!Print student information
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    //!Return 0 to indicate successful execution
    return 0;
}
