// Outfit Selector
// Ethan Greenhouse 11/1

// Library for input and output commands
#include <iostream>     

// Library for math functions (though not used in the code)
#include <cmath>        

// Library for time functions (used for random number generation)
#include <ctime>        

// Library for file handling (used to load and save clothing items)
#include <fstream>      

using namespace std;    // Allows us to use standard library functions like cout, cin, without needing to prefix them with "std::"

// Declare global variables to store the user's picked clothing items
string pickedTop, pickedBottom, pickedAccessory, pickedShoe; 

// Function to load clothing items from a file and store them into an array
void loadClothes(string fileName, string clothes[6]) {
    ifstream infile(fileName);  // Open the file for reading
    if (!infile) {  // If the file is not opened successfully, print an error and exit the program
        cout << "Unable to open file." << fileName << endl;
        exit(0);
    } else {
        // Read each clothing item from the file and store it into the array
        for (int i = 0; i < 6; i++) {
            infile >> clothes[i];
        }
    }
}

// Function to select a clothing item based on a random roll (number between 1 and 6)
string getClothingItem(string clothes[], int roll) {
    return clothes[roll - 1];  // Return the clothing item corresponding to the random roll
}

// Function to pick an outfit based on the temperature and weather conditions
string pickOutfit(char temperature, char weather, string warmTops[6], string coldTops[6], string warmBottoms[6], string coldBottoms[6], string accessories[6], string shoes[6]) {
    // Declare variables to store the selected top, bottom, accessory, and shoe
    string top;
    string bottom;
    string accessory;
    string shoe;

    // Generate random numbers between 1 and 6 for each clothing category
    int topRoll = rand() % 6 + 1;
    int bottomRoll = rand() % 6 + 1;
    int accessoryRoll = rand() % 6 + 1;
    int shoeRoll = rand() % 6 + 1;

    // Select the appropriate top and bottom based on the weather
    if (temperature == 'w') {
        top = getClothingItem(warmTops, topRoll);  // Choose a warm top
        bottom = getClothingItem(warmBottoms, bottomRoll);  // Choose a warm bottom
    } else if (temperature == 'c') {
        top = getClothingItem(coldTops, topRoll);  // Choose a cold top
        bottom = getClothingItem(coldBottoms, bottomRoll);  // Choose a cold bottom
    }

    // Select an accessory and shoe based on the weather condition
    if (weather == 's') {
        accessory = "sunglasses";  // Sunny weather means sunglasses
        shoe = getClothingItem(shoes, shoeRoll);  // Choose a random shoe
    } else if (weather == 'r') {
        accessory = "umbrella";  // Rainy weather means an umbrella
        shoe = "boots";  // Rainy weather means boots
    } else {
        accessory = getClothingItem(accessories, accessoryRoll);  // Choose a random accessory for other weather
        shoe = getClothingItem(shoes, shoeRoll);  // Choose a random shoe
    }

    // Assign the picked items to the global variables
    pickedTop = top;
    pickedBottom = bottom;
    pickedAccessory = accessory;
    pickedShoe = shoe;

    // Return the formatted outfit as a string
    return "                     " + top + "\n                 and " + bottom + "\n                with " + accessory + "\n                 and " + shoe;
}

int main() {
    srand(time(0));  // Seed the random number generator to ensure different results each time

    // Declare arrays to store clothing items for each category
    string warmTops[6], coldTops[6], warmBottoms[6], coldBottoms[6], accessories[6], shoes[6];

    // Load clothing items from files into the arrays
    loadClothes("coldTops.txt", coldTops);
    loadClothes("warmTops.txt", warmTops);
    loadClothes("coldBottoms.txt", coldBottoms);
    loadClothes("warmBottoms.txt", warmBottoms);
    loadClothes("accessories.txt", accessories);
    loadClothes("shoes.txt", shoes);

    // Declare variables for user input and feedback
    char temperature;  // Variable to store the user's choice of temperature (warm or cold)
    char weather;      // Variable to store the user's choice of weather (sunny, rainy, or none)
    string outfit;     // Variable to store the selected outfit
    char feedback;     // Variable to store the user's feedback on the outfit

    // Ask the user to enter the current temperature (warm or cold)
    cout << "What is the temperature like? Warm (w) or cold (c):" << endl;
    cin >> temperature;

    // Validate the temperature input
    while (temperature != 'w' && temperature != 'c') {
        cout << "Invalid input. What is the temperature like? Warm (w) or cold (c):" << endl;
        cin >> temperature;
    }

    // Ask the user to enter the current weather condition (sunny, rainy, or none)
    cout << "What is the weather like? Rainy (r) or sunny (s) or none (n):" << endl;
    cin >> weather;

    // Validate the weather input
    while (weather != 'r' && weather != 's' && weather != 'n') {
        cout << "Invalid input. What is the weather like? Rainy (r) or sunny (s) or none (n):" << endl;
        cin >> weather;
    }

    // Keep generating and showing new outfits until the user likes one
    do {
        outfit = pickOutfit(temperature, weather, warmTops, coldTops, warmBottoms, coldBottoms, accessories, shoes);
        cout << "Here is your outfit: \n" << outfit << endl;
        cout << "Do you like it? Yes (y) or no (n):";
        cin >> feedback;
    } while (feedback == 'n');  // Repeat until the user accepts the outfit

    // If the user likes the outfit, save it to a file
    if (feedback == 'y') {
        ofstream outfile("selectedOutfit.txt");  // Open the output file
        if (!outfile) {  // If the file cannot be opened, print an error and exit
            cout << "Unable to open outfile." << endl;
            exit(0);
        } else {
            // Write the selected outfit to the file
            outfile << pickedTop << endl;
            outfile << pickedBottom << endl;
            outfile << pickedAccessory << endl;
            outfile << pickedShoe << endl;
        }
    }

    cout << "Have a nice day!" << endl;  // Print a closing message

    return 0;  // End of the program
}
