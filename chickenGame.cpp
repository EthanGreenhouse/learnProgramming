// Chicken catch game
// Library for input output commands
#include <iostream>

// Library for math commands
#include <cmath>

// Library for time
#include <ctime>

// Lets you remove std::
using namespace std;

int main() {
    // Generates random number 1-10
    srand(time(0));
    int distance = rand() % 10 + 1;
    int userDistance;

    // Asks user how far they want to stand
    cout << "How far do you want to stand (between 1-10 feet)?" << endl;
    cin >> userDistance;

    // Compares distance between chicken and user
    if (userDistance == distance || (userDistance - distance) == 1 || (userDistance - distance)== -1) {
        cout << "You caught the chicken!" << endl;
    } else {
        cout << "You were " << abs(userDistance - distance) << " feet away from the chicken. Try again." << endl;
    }

    return 0;
}
