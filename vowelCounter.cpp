// Counts number of vowels in a string
// Includes the iostream library for input and output commands
#include <iostream>

// Includes the string library to use strings as a data type
#include <string>

// Allows functions without prefixing them with "std::"
using namespace std;

// Function to count vowels in a given string
void countVowels(string str, int &aCount, int &eCount, int &iCount, int &oCount, int &uCount) {
    // Loop through each character in the string
    for (int i = 0; i < str.length(); i++) {
        // Get character at i and convert it to lowercase to handle both cases
        char ch = str[i];

        // Check and count if character is a vowel
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
    // Variable to store the user string
    string input;

    // Variables to count the number of each vowel
    int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;

    // Ask the user to enter a string
    cout << "Please enter a string:";
    cin >> input;

    // Call the function to count vowels
    countVowels(input, aCount, eCount, iCount, oCount, uCount);
    int totalVowels = aCount + eCount + iCount + oCount + uCount;

    // Display the number of vowels found in the string
    cout << "Number of 'a' vowels: " << aCount << endl;
    cout << "Number of 'e' vowels: " << eCount << endl;
    cout << "Number of 'i' vowels: " << iCount << endl;
    cout << "Number of 'o' vowels: " << oCount << endl;
    cout << "Number of 'u' vowels: " << uCount << endl;
    cout << "Total vowel count: " << totalVowels << endl;

    return 0;
}