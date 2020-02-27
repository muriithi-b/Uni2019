
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Triangle {
    vector<double> sides;
    bool isRightAngled = false;

    public:
    Triangle(double a, double b, double c) {
        sides.push_back(a);
        sides.push_back(b);
        sides.push_back(c);

        sort(sides.begin(), sides.end());
        checkTriangleType();
    }
    void checkTriangleType() {
        double base_sq = sides[0] * sides [0];
        double height_sq = sides[1] * sides[1];
        double hyp_sq = sides[2] * sides[2];
        if (hyp_sq == (base_sq + height_sq)) {
            isRightAngled = true;
        }
    }
    double featureNotImplemented() {
        cout << "Feature not implemented yet" << endl;
        return 0;
    }
    double getArea() {
        return isRightAngled ? 0.5 * sides[0] * sides[1] : featureNotImplemented();
    }
    double getPerimeter() {
        return sides[0] + sides[1] + sides[2];
    }
};

int main () {
    Triangle tr1(5, 3,4);
    cout << "The perimeter is: " << tr1.getPerimeter() << endl;
    cout << "The Area is: " << tr1.getArea() << endl;

    double values[3];
    for (int i = 0; i < 3; i++) {
        cout << "Enter triangle side: ";
        cin >> values[i];
        cout << endl;
    }
    Triangle tr2(values[0], values[1], values[2]);
    cout << "The perimeter is: " << tr2.getPerimeter() << endl;
    cout << "The Area is: " << tr2.getArea() << endl;

    return 0;

}