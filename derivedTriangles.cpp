#include <iostream>

using namespace std;

class Shape {
    protected:
    int base, height;
  
    public:
    void setBase(int b) {
        base = b;
    }
    void setHeight(int h) {
        height = h;
    }
};

class Triangle: public Shape {
    public:
    double getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Triangle tri;
    tri.setBase(11);
    tri.setHeight(13);

    cout << "The area of tri is: " << tri.getArea() << endl;
    return 0;
}