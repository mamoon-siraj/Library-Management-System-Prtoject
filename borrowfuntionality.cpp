#include<iostream>
#include<fstream>

using namespace std;
int main() {
    const char *novelsFile = "Novels.csv";
    const char *academicsFile = "academicbooks.csv";
    const char *selfHelpFile = "SelfHelpbooks.csv";

    int cat;
    bool required_book = false;
    string str, borrow_book_title;
    
    ifstream file_1(novelsFile), file_2(academicsFile), file_3(selfHelpFile);
    ofstream temp_novelFile("temp_1.csv"), temp_academicsFile("temp_2.csv"), temp_selfHelpFile("temp_3.csv");

    if (!file_1.is_open() || !file_2.is_open() || !file_3.is_open() || 
        !temp_novelFile.is_open() || !temp_academicsFile.is_open() || !temp_selfHelpFile.is_open()) {
        cout << "Error opening file(s)." << endl;
        return 1;
    }

    cout << "Select Category from which you want to borrow book(s)." << endl;
    cout << "1. Novels." << endl;
    cout << "2. Academics." << endl;
    cout << "3. Self-help." << endl;
    cin >> cat;

    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, borrow_book_title);

    string title, author, quantity_in_str;

    switch (cat) {
        case 1:
            while (getline(file_1, str)) {
                size_t first_comma = str.find(','); 
                size_t second_comma = str.find(',', first_comma + 1); 
                size_t third_comma = str.find(',', second_comma + 1); 
                title = str.substr(first_comma + 1, second_comma - first_comma - 1); 
                author = str.substr(second_comma + 1, third_comma - second_comma - 1); 
                quantity_in_str = str.substr(third_comma + 1);

                int quantity = stoi(quantity_in_str);
                if (title == borrow_book_title) {
                    if (quantity > 0) {
                        cout << "Successfully borrowed the book." << endl;
                        quantity--;
                    } else {
                        cout << "Book currently not available in library." << endl;
                    }
                }

                temp_novelFile << title << "," << author << "," << quantity << "\n";
            }
            break;

        case 2:
            while (getline(file_2, str)) {
                size_t first_comma = str.find(','); 
                size_t second_comma = str.find(',', first_comma + 1); 
                size_t third_comma = str.find(',', second_comma + 1); 
                title = str.substr(first_comma + 1, second_comma - first_comma - 1); 
                author = str.substr(second_comma + 1, third_comma - second_comma - 1); 
                quantity_in_str = str.substr(third_comma + 1);

                int quantity = stoi(quantity_in_str);
                
                if (title == borrow_book_title) {
                    if (quantity > 0) {
                        cout << "Successfully borrowed the book." << endl;
                        quantity--;
                    } else {
                        cout << "Book currently not available in library." << endl;
                    }
                }

                temp_academicsFile << title << "," << author << "," << quantity << "\n";
            }
            break;

        case 3:
            while (getline(file_3, str)) {
                size_t first_comma = str.find(','); 
                size_t second_comma = str.find(',', first_comma + 1); 
                size_t third_comma = str.find(',', second_comma + 1); 
                title = str.substr(first_comma + 1, second_comma - first_comma - 1); 
                author = str.substr(second_comma + 1, third_comma - second_comma - 1); 
                quantity_in_str = str.substr(third_comma + 1);

                int quantity = stoi(quantity_in_str);

                if (title == borrow_book_title) {
                    if (quantity > 0) {
                        cout << "Successfully borrowed the book." << endl;
                        quantity--;
                    } else {
                        cout << "Book currently not available in library." << endl;
                    }
                }

                temp_selfHelpFile << title << "," << author << "," << quantity << "\n";
            }
            break;

        default:
            cout << "Invalid category." << endl;
            break;
    }

    file_1.close();
    file_2.close();
    file_3.close();
    temp_novelFile.close();
    temp_academicsFile.close();
    temp_selfHelpFile.close();

    if (required_book) {
        remove(novelsFile);
        remove(academicsFile);
        remove(selfHelpFile);

        rename("temp_1.csv", novelsFile);
        rename("temp_2.csv", academicsFile);
        rename("temp_3.csv", selfHelpFile);
    }

return 0;
}