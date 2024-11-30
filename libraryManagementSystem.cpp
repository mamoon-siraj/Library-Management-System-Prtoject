#include<iostream>
#include<fstream>
#include<sstream>
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

    int cat;
    int serial_no;
    string book_title;
    string author_name;

    ofstream file_1("Novel.csv", ios::app);
    ofstream file_2("Academics.csv", ios::app);
    ofstream file_3("Self-Help_books.csv", ios::app);

    cout<<"Enter the category."<<endl;
    cout<<"1. Novel."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cin>>cat;

    switch (cat)
    {
        case 1:
            if (file_1.is_open()) { 
                cout<<"Enter Serial No."<<endl;
                cin>>serial_no;

                cin.ignore();

                cout<<"Enter book title"<<endl;
                getline(cin, book_title);

                cout<<"Enter Author name."<<endl;
                getline(cin, author_name);

                file_1<<serial_no<<","<<book_title<<","<<author_name<<endl;
            }else{
                cout<<"Error. Could not open the file."<<endl;
            }

            file_1.close();
        break;

        case 2:
            if (file_2.is_open()) { 
                cout<<"Enter Serial No."<<endl;
                cin>>serial_no;

                cin.ignore();

                cout<<"Enter book title"<<endl;
                getline(cin, book_title);

                cout<<"Enter Author name."<<endl;
                getline(cin, author_name);

                file_2<<serial_no<<","<<book_title<<","<<author_name<<endl;
            }else{
                cout<<"Error. Could not open the file."<<endl;
            }

            file_2.close();
        break;

        case 3:
            if (file_3.is_open()) { 
                cout<<"Enter Serial No."<<endl;
                cin>>serial_no;

                cin.ignore();

                cout<<"Enter book title"<<endl;
                getline(cin, book_title);

                cout<<"Enter Author name."<<endl;
                getline(cin, author_name);

                file_3<<serial_no<<","<<book_title<<","<<author_name<<endl;
            }else{
                cout<<"Error. Could not open the file."<<endl;
            }

            file_3.close();
        break;

        default:
            cout<<"Enter valid category."<<endl;
            cout<<"1. Novel."<<endl;
            cout<<"2. Academics."<<endl;
            cout<<"3. Self-help."<<endl;
            cin>>cat;
        break;
    }
    
    cout << "Text added to the file successfully."<<endl;
    
}

void display_books(){

    ifstream file_1("Novels.csv");
    ifstream file_2("Self-Help_books.csv");
    ifstream file_3("Self-Help_books.csv");

    int cat;

    cout<<"Enter the category."<<endl;
    cout<<"1. Novel."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cin>>cat;

    switch (cat)
    {
        case 1:
            if (file_1.is_open()) {
                string line;
                while (getline(file_1, line)) { 
                    cout << line <<endl; 
                }

                file_1.close();
            }else{
                cout <<"Error could not open the file."<<endl; 
            }
        break;

        case 2:
            if (file_2.is_open()) {
                string line;
                while (getline(file_2, line)) { 
                cout << line <<endl; 
                }
                file_2.close();
            }else{
                 cout <<"Error could not open the file."<<endl; 
            }
        break;

        case 3:
            if (file_3.is_open()) {
                string line;
                while (getline(file_3, line)) { 
                    cout << line <<endl; 
                }
                file_3.close();
            }else{
                cout <<"Error could not open the file."<<endl; 
            }
        break;

        default:
            cout<<"Select Valid Category."<<endl;
        break;
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
            cout<<"Case two still pending."<<endl;
        break;

        case 3:
            //return borrow books.
            cout<<"Case three still pending."<<endl;
        break;

        default:
            cout<<"Selet valid option."<<endl;
            cout<<"1.View books."<<endl;
            cout<<"2.Borrow book(s)."<<endl;
            cout<<"3.Return borrow book(s)."<<endl;
        break;
    }
}

void borrow_book(){
    string book_title;
    int quantity;

    cout<<"Enter book title."<<endl;
    getline(cin, book_title);

}

