
#include<bits/stdc++.h>
using namespace std;

/**
 * @brief Represents a three-dimensional box with length, breadth, and height.
 */
class Box {
private:
    int l, b, h; ///< Length, breadth, and height of the box.

public:
    /**
     * @brief Default constructor for Box.
     */
    Box() : l(0), b(0), h(0) {}

    /**
     * @brief Parameterized constructor for Box.
     * @param length Length of the box.
     * @param breadth Breadth of the box.
     * @param height Height of the box.
     */
    Box(int length, int breadth, int height) : l(length), b(breadth), h(height) {}

    /**
     * @brief Copy constructor for Box.
     * @param B Another Box object to copy.
     */
    Box(const Box& B) : l(B.l), b(B.b), h(B.h) {}

    /**
     * @brief Getter function to get the length of the box.
     * @return Length of the box.
     */
    int getLength() {
        return l;
    }

    /**
     * @brief Getter function to get the breadth of the box.
     * @return Breadth of the box.
     */
    int getBreadth() {
        return b;
    }

    /**
     * @brief Getter function to get the height of the box.
     * @return Height of the box.
     */
    int getHeight() {
        return h;
    }

    /**
     * @brief Calculates and returns the volume of the box.
     * @return Volume of the box.
     */
    long long CalculateVolume() {
        return ((long long)l * b * h);
    }

    /**
     * @brief Overloaded less than operator to compare two boxes.
     * @param b1 First box to compare.
     * @param b2 Second box to compare.
     * @return True if b1 is less than b2, false otherwise.
     */
    friend bool operator < (Box& b1, Box& b2) {
        if ((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
            (b1.l == b2.l && b1.b == b2.b && b1.h < b2.h))
            return true;
        else
            return false;
    }

    /**
     * @brief Overloaded stream insertion operator to output box information.
     * @param s Output stream.
     * @param b1 Box object to output.
     * @return Output stream.
     */
    friend ostream& operator << (ostream& s, Box& b1) {
        s << b1.l << " " << b1.b << " " << b1.h;
        return s;
    }
};

/**
 * @brief Checks different operations on Box objects based on user input.
 */
void check2() {
    int n;
    cin >> n;
    Box temp;

    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                cout << "Lesser\n";
            }
            else {
                cout << "Greater\n";
            }
        }
        if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

/**
 * @brief Main function to call check2 function.
 * @return 0 on successful execution.
 */
int main() {
    check2();
    return 0;
}
