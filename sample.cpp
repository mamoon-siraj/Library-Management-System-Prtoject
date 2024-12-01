#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main(){
    const char *a = "Novels.csv";

    ifstream file_1(a);

    stringstream file_string;
    string serial_no, title, author, quantity_in_str;
    int quantity;

    stringstream files_tring
   
    while (getline(file_1, str)) {
    file_string.str(str);
    file_string.clear();
    getline(file_string, title, ',');
    getline(file_string, author, ',');
    getline(file_string, quantity_in_str, ',');

    // Debugging step: print the quantity string before converting
    cout << "Quantity in string format: '" << quantity_in_str << "'" << endl;

    try {
        quantity = stoi(quantity_in_str); // This is where the error happens
    } catch (const std::invalid_argument& e) {
        cout << "Invalid quantity: " << quantity_in_str << endl;
        continue; // Skip this line and move to the next one
    }
}

     
}