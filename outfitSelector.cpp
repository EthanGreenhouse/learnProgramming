// Outfit Selector
#include <iostream>     // Library for input output
#include <cmath>        // Library for math
#include <ctime>        // Library for time
#include <fstream>      // Library for files

using namespace std;    // Lets you remove std::

string pickedTop, pickedBottom, pickedAccessory, pickedShoe; // Variables for individually picked outfit items

// Function to load clothing items from a file and stores into array
void loadClothes(string fileName, string clothes[6]) {
    ifstream infile(fileName);
    if (!infile) {      // Check if the file is open
        cout << "Unable to open file." << fileName << endl;
        exit(0);
    } else {
        // Read each line into the array
        for (int i = 0; i < 6; i++) {
            infile >> clothes[i];
        }
    }
}

// Function to select a clothing item based on a random roll
string getClothingItem(string clothes[], int roll) {
    return clothes[roll - 1];
}

// Function to pick an outfit based on the weather
string pickOutfit(char temperature, char weather, string warmTops[6], string coldTops[6], string warmBottoms[6], string coldBottoms[6], string accessories[6], string shoes[6]) {
    // Declare top and bottom variables
    string top;
    string bottom;
    string accessory;
    string shoe;

    // Generate random numbers between 1 and 6
    int topRoll = rand() % 6 + 1;
    int bottomRoll = rand() % 6 + 1;
    int accessoryRoll = rand() % 6 + 1;
    int shoeRoll = rand() % 6 + 1;

    // Select the appropriate top and bottom based on the weather
    if (temperature == 'w') {
        top = getClothingItem(warmTops, topRoll);
        bottom = getClothingItem(warmBottoms, bottomRoll);
    } else if (temperature == 'c') {
        top = getClothingItem(coldTops, topRoll);
        bottom = getClothingItem(coldBottoms, bottomRoll);
    }

    // Select an accessory and shoe
    if (weather == 's') {
        accessory = "sunglasses";
        shoe = getClothingItem(shoes, shoeRoll);
    } else if (weather == 'r') {
        accessory = "umbrella";
        shoe = "boots";
    } else {
        accessory = getClothingItem(accessories, accessoryRoll);
        shoe = getClothingItem(shoes, shoeRoll);
    }

    // Assign individually picked items
    pickedTop = top;
    pickedBottom = bottom;
    pickedAccessory = accessory;
    pickedShoe = shoe;

    return "                     " + top + "\n                 and " + bottom + "\n                with " + accessory + "\n                 and " + shoe;
}

int main() {
    srand(time(0)); // Seed the random number generator

    string warmTops[6], coldTops[6], warmBottoms[6], coldBottoms[6], accessories[6], shoes[6]; // Arrays to store items

    // Load clothing items
    loadClothes("coldTops.txt", coldTops);
    loadClothes("warmTops.txt", warmTops);
    loadClothes("coldBottoms.txt", coldBottoms);
    loadClothes("warmBottoms.txt", warmBottoms);
    loadClothes("accessories.txt", accessories);
    loadClothes("shoes.txt", shoes);

    char temperature;   // Variable for user input of temperature
    char weather;       // Variable for extra weather
    string outfit;      // Variable for picked outfit
    char feedback;      // Variable for user's feedback

    // Ask user to enter the current temperature
    cout << "What is the temperature like? Warm (w) or cold (c):" << endl;
    cin >> temperature;

    // Validate the user's input for the temperature
    while (temperature != 'w' && temperature != 'c') {
        cout << "Invalid input. What is the temperature like? Warm (w) or cold (c):" << endl;
        cin >> temperature;
    }

    // Ask user to enter the current weather
    cout << "What is the weather like? Rainy (r) or sunny (s) or none (n):" << endl;
    cin >> weather;

    // Validate the user's input for the weather
    while (weather != 'r' && weather != 's' && weather != 'n') {
        cout << "Invalid input. What is the weather like? Rainy (r) or sunny (s) or none (n):" << endl;
        cin >> weather;
    }

    // Give a new outfit until the user like the outfit
    do {
        outfit = pickOutfit(temperature, weather, warmTops, coldTops, warmBottoms, coldBottoms, accessories, shoes);
        cout << "Here is your outfit: \n" << outfit << endl;
        cout << "Do you like it? Yes (y) or no (n):";
        cin >> feedback;
    } while (feedback == 'n');

    if (feedback == 'y') {
        ofstream outfile("selectedOutfit.txt");
        if (!outfile) {
            cout << "Unable to open outfile." << endl;
            exit(0);
        } else {
            outfile << pickedTop << endl;
            outfile << pickedBottom << endl;
            outfile << pickedAccessory << endl;
            outfile << pickedShoe << endl;
        }
    }

    cout << "Have a nice day!" << endl;

    return 0;
}