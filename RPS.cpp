// Library for input output commands
#include <iostream>

// Library for time
#include <ctime>

// Lets you remove std::
using namespace std;

int main() {
    // Declares char variable that stores user's choice
    string userChoice;

    // Declares winner variable
    string winner;

    // Declares valid input variable
    bool valid = false;

    // Declares win counters
    int userWins = 0;
    int computerWins = 0;

    // Generates seed
    srand(time(0));

    // Outputs welcome message
    cout << "Welcome to Rock, Paper, Scissors game!" << endl;

    // Play three rounds
    for (int i = 1; i < 4; i++) {
        // Reset valid checker
        valid = false;

        // Generates and assigns random number
        int random = rand() % 3;
        string computerChoice;
        if (random == 0) {
            computerChoice = "rock";
        } else if (random == 1) {
            computerChoice = "paper";
        } else if (random == 2) {
            computerChoice = "scissors";
        }

        // Checks if user input is valid
        while (valid == false) {
            cout << "Round " << i << ": Type 'rock', 'paper', or 'scissors' to play" << endl;
            cin >> userChoice;
            if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors") {
                valid = true;
            } else {
                cout << "Invalid input. Try again." << endl;
            }
        }

        // Determines winner of the round
        if (userChoice == computerChoice) {
            winner = "Tie...";
        } else if ((userChoice == "rock" && computerChoice == "scissors") ||
                   (userChoice == "paper" && computerChoice == "rock") ||
                   (userChoice == "scissors" && computerChoice == "paper")) {
            winner = "You Win!";
            userWins++;
        } else {
            winner = "You Lost.";
            computerWins++;
        }

        // Output result of the round
        cout << "Computer chose: " << computerChoice << ". " << winner << endl;
    }

    // Determine overall winner
    if (userWins > computerWins) {
        cout << "Congratulations! You won the best of three!" << endl;
    } else if (computerWins > userWins) {
        cout << "You lost the best of three. Try again." << endl;
    } else {
        cout << "It's a tie..." << endl;
    }

    return 0;
}