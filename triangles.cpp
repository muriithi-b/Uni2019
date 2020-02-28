
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

class Triangle {
    int sideA, sideB, sideC;
    
    bool checkValidity(int a, int b, int c) {
        //check if the dimensions are valid for a triangle
        if (a + b > c && a + c > b && c + b > a) {
            return true;
        }else {
            return false;
        }
    }

    public:
    Triangle(int a, int b, int c) {
        if (!checkValidity(a, b, c)) {
            /*----------------------------
              Implement Exception
              ----------------------------
            */
            cout << "Sides provided not valid for a triangle." << endl;
            cout << "You\'ll be provided with a default triangle bwoy." << endl;
            sideA = 3; sideB = 4; sideC = 5;
        }else {
            sideA = a; sideB = b; sideC = c;
        }
    }
    int getPerimeter() {
        return sideA + sideB + sideC;
    }
    double getArea() {
        //Using Heron's Formula
        double semi_per = (double)getPerimeter() / 2;
        return sqrt(semi_per * (semi_per - sideA) * (semi_per - sideB) * (semi_per - sideC));
    }
};

int main() {
    int a, b, c;
    cout << "Enter dimension of triangle delimetered by space" << endl;
    cout << ">> ";
    cin >> a; cin >> b; cin >> c;
    Triangle t1(a, b, c);
    cout << "Perimeter: " << t1.getPerimeter() << endl;
    cout << "Area: " << t1.getArea() << endl;
    return 0;
}