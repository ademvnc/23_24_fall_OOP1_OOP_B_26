/**
    *@link https://www.hackerrank.com/challenges/attribute-parser/problem
    *@file Attribute_Parser.cpp
    *@brief This program reads an HRML source program and queries and prints the corresponding values.
    *@details This program reads an HRML source program and queries and prints the corresponding values.
    *The program uses a map to store the tag attributes.
    *@return 0 on successful execution.
    *@author ademvnc
    *@date 10/08/2021
    *@version 1.0
    *@note This program is a solution to the ninth question of the HackerRank C++ Basic Certification Test.

 */

#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Main function to process HRML and queries.
 * @return 0 on successful execution.
 */
int main() {
    int n, q, i; //! Number of lines in HRML and number of queries.
    cin >> n >> q;

    string temp;
    vector<string> hrml; //! Vector to store HRML source lines.
    vector<string> quer; //! Vector to store queries.

    cin.ignore(); //!Ignore newline after n and q

    //!Read HRML source program
    for (i = 0; i < n; i++) {
        getline(cin, temp);
        hrml.push_back(temp);
    }

    //!Read queries
    for (i = 0; i < q; i++) {
        getline(cin, temp);
        quer.push_back(temp);
    }

    map<string, string> m; //! Map to store tag attributes.
    vector<string> tag;

    //!Process HRML source program
    for (i = 0; i < n; i++) {
        temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp.substr(0, 2) == "</") {
            tag.pop_back();
        } else {
            stringstream ss;
            ss.str("");
            ss << temp;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            string temp1 = "";
            if (tag.size() > 0) {
                temp1 = *tag.rbegin();
                temp1 = temp1 + "." + t1;
            } else
                temp1 = t1;
            tag.push_back(temp1);
            m[*tag.rbegin() + "~" + p1] = v1;
            while (ss) {
                ss >> p1 >> ch >> v1;
                m[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }

    //!Process queries and print the corresponding values
    for (i = 0; i < q; i++) {
        if (m.find(quer[i]) == m.end())
            cout << "Not Found!\n";
        else
            cout << m[quer[i]] << endl;
    }

    return 0;
}
