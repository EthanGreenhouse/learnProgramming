// Calculates tip each person should pay for dinner
// Library for input output commands
#include <iostream>

// Library for math commands
#include <cmath>

// Lets you remove std::
using namespace std;

int main() {
    // Declare and initializes variables
    double billTotal;
    double people;
    double tipTotal;
    double tip;

    // Asks user for the total cost of bill
    cout << "Enter cost of the bill: " << endl;
    cin >> billTotal;

    // Asks user for the amount of people in group
    cout << "Enter amount of people in the group: " << endl;
    cin >> people;

    // Calculates total amount of tip
    tipTotal = billTotal * 1.15;

    // Calculates tip per person
    tip = tipTotal / people;

    // Returns tip amount each person should pay
    cout << "Tip paid per person: " << tip << endl;

    return 0;
}
