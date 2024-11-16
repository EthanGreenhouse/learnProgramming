// Chicken catch game
// Ethan Greenhouse 9/18

// Library for input and output commands
#include <iostream>

// Library for mathematical functions like abs()
#include <cmath>

// Library for time functions (used to generate random numbers)
#include <ctime>

// Allows us to use standard functions and objects like cout and cin without prefixing "std::"
using namespace std;

int main() {
    // Initialize random number generator with the current time as the seed
    srand(time(0));  
    // Generate a random number between 1 and 10 representing the chicken's distance
    int distance = rand() % 10 + 1;
    
    // Variable to store the user's chosen distance
    int userDistance;

    // Prompt the user to enter how far they want to stand (between 1-10 feet)
    cout << "How far do you want to stand (between 1-10 feet)?" << endl;
    cin >> userDistance;

    // Compare the user's distance with the chicken's distance
    // If the user's distance matches or is one foot away from the chicken's position, they catch the chicken
    if (userDistance == distance || (userDistance - distance) == 1 || (userDistance - distance) == -1) {
        cout << "You caught the chicken!" << endl;
    } else {
        // If the user misses, output the distance they were away from the chicken and prompt them to try again
        cout << "You were " << abs(userDistance - distance) << " feet away from the chicken. Try again." << endl;
    }

    // End of the program
    return 0;
}
