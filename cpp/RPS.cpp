// Rock, paper, scissors game
// Ethan Greenhouse 9/27/2024

// Library for input and output commands
#include <iostream>

// Library for time-related functions (used for random number generation)
#include <ctime>

// Lets you use common standard functions like cout and cin without prefixing with "std::"
using namespace std;

int main() {
    // Declares a string variable to store the user's choice (rock, paper, or scissors)
    string userChoice;

    // Declares a string to store the result of the round (winner)
    string winner;

    // Boolean variable to check if the user input is valid
    bool valid = false;

    // Declares counters for the number of wins for the user and computer
    int userWins = 0;
    int computerWins = 0;

    // Seeds the random number generator to ensure different results each time the program runs
    srand(time(0));

    // Outputs a welcome message
    cout << "Welcome to Rock, Paper, Scissors game!" << endl;

    // Play three rounds of the game
    for (int i = 1; i < 4; i++) {
        // Reset the valid input checker for the new round
        valid = false;

        // Generates a random number (0, 1, or 2) to determine the computer's choice
        int random = rand() % 3;
        string computerChoice;

        // Assigns the computer's choice based on the random number
        if (random == 0) {
            computerChoice = "rock";
        } else if (random == 1) {
            computerChoice = "paper";
        } else if (random == 2) {
            computerChoice = "scissors";
        }

        // Repeatedly asks the user for a valid input until they enter 'rock', 'paper', or 'scissors'
        while (valid == false) {
            cout << "Round " << i << ": Type 'rock', 'paper', or 'scissors' to play" << endl;
            cin >> userChoice;

            // Checks if the user's input is valid
            if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors") {
                valid = true;  // Mark the input as valid if it is one of the allowed choices
            } else {
                cout << "Invalid input. Try again." << endl;  // Ask again if the input is invalid
            }
        }

        // Determines the winner of the round by comparing user and computer choices
        if (userChoice == computerChoice) {
            winner = "Tie...";  // If both choices are the same, it's a tie
        } else if ((userChoice == "rock" && computerChoice == "scissors") ||   // Rock beats scissors
                   (userChoice == "paper" && computerChoice == "rock") ||     // Paper beats rock
                   (userChoice == "scissors" && computerChoice == "paper")) { // Scissors beats paper
            winner = "You Win!";
            userWins++;  // Increment user win count
        } else {
            winner = "You Lost.";
            computerWins++;  // Increment computer win count
        }

        // Outputs the result of the round: computer's choice and the winner
        cout << "Computer chose: " << computerChoice << ". " << winner << endl;
    }

    // Determine the overall winner based on who has more wins
    if (userWins > computerWins) {
        cout << "Congratulations! You won the best of three!" << endl;
    } else if (computerWins > userWins) {
        cout << "You lost the best of three. Try again." << endl;
    } else {
        cout << "It's a tie..." << endl;  // If both have equal wins, it's a tie
    }

    return 0;  // End of the program
}
