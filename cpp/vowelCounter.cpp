// Program to count the number of vowels in a given string
// Ethan Greenhouse 
// 10/29/2024

// Includes the iostream library for input and output operations
#include <iostream>

// Includes the string library to handle string data type
#include <string>

// Allows functions like cout and cin to be used without "std::" prefix
using namespace std;

// Function to count vowels in a given string
// Parameters: str (input string), and references to vowel count variables
void countVowels(string str, int &aCount, int &eCount, int &iCount, int &oCount, int &uCount) {
    // Loop through each character in the input string
    for (int i = 0; i < str.length(); i++) {
        // Get the character at position i
        char ch = str[i];

        // Check if the character is a vowel (case insensitive) and increment the respective counter
        if (ch == 'a' || ch == 'A') {
            aCount++;
        } else if (ch == 'e' || ch == 'E') {
            eCount++;
        } else if (ch == 'i' || ch == 'I') {
            iCount++;
        } else if (ch == 'o' || ch == 'O') {
            oCount++;
        } else if (ch == 'u' || ch == 'U') {
            uCount++;
        }
    }
}

int main() {
    // Variable to store the user input string
    string input;

    // Variables to store the count of each vowel
    int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;

    // Prompt the user to enter a string
    cout << "Please enter a string: ";
    cin >> input;

    // Call the function to count vowels in the input string
    countVowels(input, aCount, eCount, iCount, oCount, uCount);
    
    // Calculate the total number of vowels
    int totalVowels = aCount + eCount + iCount + oCount + uCount;

    // Display the count of each vowel
    cout << "Number of 'a' vowels: " << aCount << endl;
    cout << "Number of 'e' vowels: " << eCount << endl;
    cout << "Number of 'i' vowels: " << iCount << endl;
    cout << "Number of 'o' vowels: " << oCount << endl;
    cout << "Number of 'u' vowels: " << uCount << endl;
    
    // Display the total count of vowels
    cout << "Total vowel count: " << totalVowels << endl;

    // Indicate successful program completion
    return 0;
}
