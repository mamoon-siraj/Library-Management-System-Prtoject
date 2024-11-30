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

    int serial_no;
    string book_title;
    string author_name;

    ofstream file("Books.txt", ios::app); 

    if (file.is_open()) { 
        cout<<"Enter Serial No."<<endl;
        cin>>serial_no;

        cin.ignore();

        cout<<"Enter book title"<<endl;
        getline(cin, book_title);

        cout<<"Enter Author name."<<endl;
        getline(cin, author_name);

        file<<serial_no<<"\t"<<book_title<<" by "<<author_name<<endl;
    }
    else{
        cout<<"Error. Could not open the file."<<endl;
    }

    file.close();
    cout << "Text added to the file successfully."<<endl;
    
}