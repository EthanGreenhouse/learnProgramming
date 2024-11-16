// Gives area and circumference of a circle given a radius
// Library for input output commands
#include <iostream>

// Library for math commands
#include <cmath>

// Lets you remove std::
using namespace std;

int main() {
    // Declare and initializes variables
    float radius;
    float area;
    float circumference;

    // Asks user for radius of a circle
    cout << "Enter the radius of the circle: " << endl;
    cin >> radius;

    // Calculates area of the circle
    area = radius * radius * M_PI;

    // Calculates circumference of the circle
    circumference = radius * 2 * M_PI;

    // Returns calculations
    cout << "Area of the circle is: " << area << endl;
    cout << "Circumference of the circle is: " << circumference << endl;

    return 0;
}
