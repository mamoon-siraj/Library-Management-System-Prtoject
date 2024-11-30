#include<iostream>
#include<fstream>
using namespace std;

void librarian_menu();
void display_books();
void add_books();

void student_menu();

int main(){

    int designation;
    
    cout<<"Please select the apprpriate."<<endl;
    cout<<"1-Librarian Menu."<<endl;
    cout<<"2-Student Menu."<<endl;
    cin>>designation;

    switch (designation)
    {
        case 1:
            librarian_menu();
        break;

        case 2:
            student_menu();   
        break;

        default:
            cout<<"Invalid Designation"<<endl;
        break;
    }

}

void librarian_menu(){

    int option;

    cout<<"Select the appropriate."<<endl;
    cout<<"1.Add book(s)."<<endl;
    cout<<"2.Veiw books."<<endl;

    cin>>option;

    switch (option)
    {
        case 1:
            add_books();
        break;

        case 2:
            display_books();
        break;
    
        default:
            cout<<"Kindly Select among the given options."<<endl;
            cout<<"1.Add Book(s)."<<endl;
            cout<<"2.View Books."<<endl;
        break;
    }
}

void display_books(){
     ifstream file("Books.txt"); // Open the file for reading

    if (!file.is_open()) { // Check if the file opened successfully
        cerr << "Error: Could not open the file.\n";        
    }
    else{
    string line;
    while (getline(file, line)) { // Read the file line by line
        cout << line << '\n\n'; // Display the line on the console
    }

    file.close(); // Close the file (optional)
    }
}

