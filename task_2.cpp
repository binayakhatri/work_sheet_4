#include <iostream>

using namespace std;

class Circle
 {

private:
    int rad;

public:
    // Constructor to initialize the radius
    Circle(int radius) : rad(radius) {}

    // Function to get the radius
    int getRadius() const {
        return rad;
    }

    // Function to set the radius
    void setRadius(int radius) {
        if (radius < 0) {
            throw 10; // Exception code 10 if radius is negative
        }
        rad = radius;
    }

    // Overload the subtraction operator
    Circle& operator-(int n) {
        setRadius(rad - n);
        return *this;
    }

    // Function to display the radius
    void show() const {
        cout << "Radius: " << rad << endl;
    }
};

class Ellipse : public Circle {
private:
    int axis;

public:
    // Constructor to initialize the radius and axis
    Ellipse(int radius, int ax) : Circle(radius), axis(ax) {}

    // Function to get the axis
    int getAxis() const {
        return axis;
    }

    // Function to set the axis
    void setAxis(int ax) {
        if (ax < 0) {
            throw 20; // Exception code 20 if axis is negative
        }
        axis = ax;
    }

    // Overload the subtraction operator
    Ellipse& operator-(int n) {
        // Subtract from radius using the base class operator-
        Circle::operator-(n);

        // Subtract from axis
        setAxis(axis - n);
        return *this;
    }

    // Function to display the radius and axis
    void show() const {
        cout << "Radius: " << getRadius() << endl;
        cout << "Axis: " << axis << endl;
    }
};

// Function to perform the subtraction operation
void f(Circle& c, int n) {
    try {
        c = c - n;
        c.show();
    } catch (int ex) {
        if (ex == 10) {
            cout << "Exception code 10: Negative radius" << endl;
        } else if (ex == 20) {
            cout << "Exception code 20: Negative axis" << endl;
        }
    }
}

int main() {
    // Prompt user to enter values for the Circle
    cout << "Enter radius for Circle: ";
    int circleRadius;
    cin >> circleRadius;
    Circle cir(circleRadius);

    // Prompt user to enter values for the Ellipse
    cout << "Enter radius for Ellipse: ";
    int ellipseRadius;
    cin >> ellipseRadius;
    cout << "Enter axis for Ellipse: ";
    int ellipseAxis;
    cin >> ellipseAxis;
    Ellipse ell(ellipseRadius, ellipseAxis);

    // Reference to Circle and Ellipse objects
    Circle& r1 = cir;
    Circle& r2 = ell;

    // Prompt user to enter value to subtract
    cout << "Enter value to subtract: ";
    int valueToSubtract;
    cin >> valueToSubtract;

    // Perform operations using function f()
    cout << "Result of subtracting from Circle: ";
    f(r1, valueToSubtract);

    cout << "Result of subtracting from Ellipse: ";
    f(r2, valueToSubtract);

    return 0;
}

