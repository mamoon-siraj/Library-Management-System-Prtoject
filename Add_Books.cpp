#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void add_books();
int main() {
    add_books();

    return 0;
}
void add_books(){
    const string filename = "Books.txt"; // File to write to
    ofstream file(filename, std::ios::app); // Open in append mode

    if (!file.is_open()) { // Check if the file opened successfully
        cerr << "Error: Could not open the file \"" << filename << "\".\n";
    }
    else{
    cout << "Enter text to add to the file (type 'exit' to stop):\n";
    string input;

    while (true) {
        getline(cin, input); // Get input from the user
        if (input == "exit") {
            break; // Stop if the user types 'exit'
        }
        file << input << '\n'; // Write the input to the file
    }

    file.close(); // Close the file
    cout << "Text added to the file successfully.\n";
    }
}