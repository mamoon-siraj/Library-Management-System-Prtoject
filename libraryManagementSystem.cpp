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

void display_books(){
    ifstream file("Books.txt");

    if (file.is_open()) {
          string line;
        while (getline(file, line)) { 
            cout << line <<endl; 
        }

        file.close();
    }   
    else{
        cout <<"Error could not open the file."<<endl; 
    }

}

void student_menu(){

    int option;

    cout<<"Select the appropriate."<<endl;
    cout<<"1.View books."<<endl;
    cout<<"2.Borrow book(s)."<<endl;
    cout<<"3.Return borrow book(s)."<<endl;

    cin>>option;

    switch (option)
    {
        case 1:
            display_books();
        break;

        case 2:
            //for borrowing books.
        break;

        case 3:
            //return borrow books.
        break;

        default:
            cout<<"Selet valid option."<<endl;
            cout<<"1.View books."<<endl;
            cout<<"2.Borrow book(s)."<<endl;
            cout<<"3.Return borrow book(s)."<<endl;
        break;
    }
}

