// Checks and Treasures game
// Ethan Greenhouse
// 1/15/2025

#include <iostream>     // Library for i/o functions
#include <ctime>        // Library for time functions
#include <unistd.h>     // For sleep function

using namespace std;    // Removes need to prefix with std::

// Display game
void display(int treasure[]) {
    for (int i = 0; i < 5; i++) {
        cout << " _______ ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "|       |";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "|  $" << treasure[i] << "   |";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "|_______|";
    }
    cout << endl;
}

// Get input from player
void getPlayerInput(int &chest, int &numTreasure, int treasure[]) {
    bool check = false;

    while (check == false) {
        cout << "Enter the chest number (1-" << 5 << "): ";
        cin >> chest;

        cout << "Enter the number of treasure to remove (1, 2, or 3): ";
        cin >> numTreasure;

        if (chest < 1 || chest > 5) {
            cout << "Grr invalid chest number. Try again mate." << endl;
        } else if (numTreasure < 1 || numTreasure > 3 || numTreasure > treasure[chest - 1]) {
            cout << "Grr invalid number of treasure. Try again mate." << endl;
        } else {
            check = true;
        }
    }
}

// Computer's turn
void getComputerInput(int &chest, int &numTreasure, int treasure[]) {
    bool check = false;

    while (check == false) {
        chest = rand() % 5 + 1;
        if (treasure[chest - 1] > 0) {
            numTreasure = rand() % 3 + 1;
            if (numTreasure <= treasure[chest - 1]) {
                check = true;
            }
        }
    }
    sleep(1);
    cout << "Computer chose chest " << chest << " and removed " << numTreasure << " treasure." << endl;
}

// Removes treasure from chest
void removeTreasure(int chest, int numTreasure, int treasure[]) {
    treasure[chest - 1] -= numTreasure;
}

// Check if game is over
bool isGameOver(int treasure[]) {
    for (int i = 0; i < 5; i++) {
        if (treasure[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int treasure[5];          
    int currentPlayer = 1;     
    int gamemode = 0;

    srand(time(0)); 

    for (int i = 0; i < 5; i++) {
        treasure[i] = rand() % 9 + 1;
    }

    cout << "Arggg, welcome to Chests and Treasures!" << endl;
    sleep(1);
    cout << "Don't be the last to remove a treasure, or face your DOOM!" << endl;
    sleep(1);

    // Game mode selection
    while (gamemode != 1 && gamemode != 2) {
        cout << "Select gamemode: Player vs Player (1) or Player vs Computer (2): ";
        cin >> gamemode;

        if (gamemode != 1 && gamemode != 2) {
            cout << "Grr invalid selection! Please choose 1 or 2. Try again mate." << endl;
        }
    }

    bool gameActive = true;
    while (gameActive) {
        display(treasure);

        if (gamemode == 2 && currentPlayer == 2) {
            cout << "Turn: Computer" << endl;
            int chest, numTreasure;
            getComputerInput(chest, numTreasure, treasure);
            removeTreasure(chest, numTreasure, treasure);
        } else {
            cout << "Turn: Player " << currentPlayer << endl;
            int chest, numTreasure;
            getPlayerInput(chest, numTreasure, treasure);
            removeTreasure(chest, numTreasure, treasure);
        }

        gameActive = !isGameOver(treasure);

        if (gameActive == false) {
            if (gamemode == 2 && currentPlayer == 1) {
                cout << "The Computer wins. Better luck next time mate!" << endl;
            } else {
                cout << "Player " << currentPlayer << " wins!" << endl;
            }
        } else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    return 0;
}