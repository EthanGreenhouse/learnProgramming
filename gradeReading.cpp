// Counts number of grades of file and outputs results into new file
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int A = 0, B = 0, C = 0, D = 0, F = 0; // Initialize counters for each grade
    char grade; // Holds grade from file

    ifstream infile("grades.txt"); // Open input file

    // Check if input file opened successfully
    if (!infile) {
        cout << "Unable to open infile";
        exit(0);
    } else {
        // Loop through each grade in file
        while (infile >> grade) {
            // Check letter of grade and count
            if (grade == 'A') {
                A++;
            } else if (grade == 'B') {
                B++;
            } else if (grade == 'C') {
                C++;
            } else if (grade == 'D') {
                D++;
            } else if (grade == 'F') {
                F++;
            } else {
                cout << "Invalid grade";
            }
        }
    } infile.close();

    ofstream outfile("summary.txt"); // Open output file

    // Check if output file opened successfully
    if (!outfile) {
        cout << "Unable to open outfile";
        exit(0);
    }

    // Write counts of each grade into output file
    outfile << "A: " << A << "\n";
    outfile << "B: " << B << "\n";
    outfile << "C: " << C << "\n";
    outfile << "D: " << D << "\n";
    outfile << "F: " << F << "\n";

    return 0;
}
