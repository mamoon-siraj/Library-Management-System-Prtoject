#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void display_books();
int main(){
    // const std::string filename = "Books.txt";
    // std::string Books;
    // // std::cout << "Enter the name of the file to display: ";
    // // std::cin >> filename;
    display_books();

    struct{
        string bookTitle;
        string authorName;     
    }bookInfo;

    cout<<"Enter book title or Author name."<<endl;
    getline(cin, bookInfo.bookTitle);
    cin.ignore();
    getline(cin, bookInfo.authorName);
   
    return 0;
}
void display_books(){
     ifstream file("Books.txt"); // Open the file for reading

    if (!file.is_open()) { // Check if the file opened successfully
        cerr << "Error: Could not open the file.\n";        
    }
    else{
    string line;
    while (getline(file, line)) { // Read the file line by line
        cout << line << '\n'; // Display the line on the console
    }

    file.close(); // Close the file (optional)
    }
}