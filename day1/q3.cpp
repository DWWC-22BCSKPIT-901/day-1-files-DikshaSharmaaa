#include <iostream>
using namespace std;

// Function to calculate the area of a circle
double area(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}

// Function to calculate the area of a rectangle
int area(int length, int breadth) {
    return length * breadth;
}

// Function to calculate the area of a triangle
double area(double base, double height) {
    return 0.5 * base * height;
}

int main() {
    // Input for the circle
    double radius;
    cin >> radius;

    // Input for the rectangle
    int length, breadth;
    cin >> length >> breadth;

    // Input for the triangle
    double base, height;
    cin >> base >> height;

    // Output the areas
    cout << area(radius) << endl;         // Area of the circle
    cout << area(length, breadth) << endl; // Area of the rectangle
    cout << area(base, height) << endl;    // Area of the triangle

    return 0;
}
