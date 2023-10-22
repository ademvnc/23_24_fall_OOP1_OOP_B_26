
/**
 * @link https://www.hackerrank.com/challenges/c-tutorial-class/problem
 * @file Class.cpp
 * @brief This program demonstrates the usage of the Student class.
 * @details This program reads student information from the user and prints the information to standard output.
 * The program uses a class to store the student information.
 * @return 0 on successful execution.
 * @author ademvnc 
 * @date 10/08/2021
 * @version 1.0
 * @note This program is a solution to the fourteenth question of the HackerRank C++ Basic Certification Test.
 */

#include <iostream>
#include <sstream>

using namespace std;

/**
 * @brief Represents a student with age, first name, last name, and standard information.
 */
class Student {
    int age, standard; ///< Age and standard of the student.
    string first_name, last_name; ///< First and last name of the student.

public:
    /**
     * @brief Sets the age of the student.
     * @param a Age of the student.
     */
    void set_age(int a) {
        age = a;
    }

    /**
     * @brief Sets the standard of the student.
     * @param s Standard of the student.
     */
    void set_standard(int s) {
        standard = s;
    }

    /**
     * @brief Sets the first name of the student.
     * @param fn First name of the student.
     */
    void set_first_name(string fn) {
        first_name = fn;
    }

    /**
     * @brief Sets the last name of the student.
     * @param ln Last name of the student.
     */
    void set_last_name(string ln) {
        last_name = ln;
    }

    /**
     * @brief Gets the age of the student.
     * @return Age of the student.
     */
    int get_age() {
        return age;
    }

    /**
     * @brief Gets the standard of the student.
     * @return Standard of the student.
     */
    int get_standard() {
        return standard;
    }

    /**
     * @brief Gets the first name of the student.
     * @return First name of the student.
     */
    string get_first_name() {
        return first_name;
    }

    /**
     * @brief Gets the last name of the student.
     * @return Last name of the student.
     */
    string get_last_name() {
        return last_name;
    }

    /**
     * @brief Converts student information to a formatted string.
     * @return Formatted string representation of the student information.
     */
    string to_string() {
        stringstream ss;
        char c = ',';
        ss << age << c << first_name << c << last_name << c << standard;
        return ss.str();
    }
};

/**
 * @brief Main function to demonstrate the usage of the Student class.
 * @return 0 on successful execution.
 */
int main() {
    int age, standard;
    string first_name, last_name;

    //!Read student information from the user
    cin >> age >> first_name >> last_name >> standard;

    //!Create an instance of the Student class and set its attributes
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    //!Print student information using the getter methods
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    //!Return 0 to indicate successful execution
    return 0;
}
