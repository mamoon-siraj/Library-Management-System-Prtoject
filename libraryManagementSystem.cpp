#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

void librarian_menu();
void display_books();
void add_books();
void student_menu();
void borrow_book();

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

    int cat, serial_no;
    string book_title, author_name;
    ofstream file_1("Novel.csv", ios::app), file_2("Academics.csv", ios::app), file_3("Self-Help_books.csv", ios::app);

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
    
    int cat;
    ifstream file_1("Novels.csv"), file_2("Self-Help_books.csv"), file_3("Self-Help_books.csv");
   
    cout<<"Enter the category."<<endl;
    cout<<"1. Novel."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cin>>cat;

    switch (cat)
    {
        case 1:
            if (file_1.is_open()) {
                string str;
                while (getline(file_1, str)) { 
                    cout << str <<endl; 
                }

                file_1.close();
            }else{
                cout <<"Error could not open the file."<<endl; 
            }
        break;

        case 2:
            if (file_2.is_open()) {
                string str;
                while (getline(file_2, str)) { 
                cout << str <<endl; 
                }
                file_2.close();
            }else{
                 cout <<"Error could not open the file."<<endl; 
            }
        break;

        case 3:
            if (file_3.is_open()) {
                string str;
                while (getline(file_3, str)) { 
                    cout << str <<endl; 
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
   
    cin>>option;

    switch (option)
    {
        case 1:
            display_books();
        break;

        case 2:
            borrow_book();
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

    char *a = "Novels.csv";
    char *b = "Academics_Books.csv";
    char *c = "Self-Help_books.csv";

    int cat;
    bool required_book = false;
    string str, borrow_book_title;
    

    ifstream file_1("Novels.csv"), file_2("Acaemics_Books.csv"), file_3("Self-Help_books.csv");  
    ofstream temp_novelFile("temp_1.csv"), temp_academicsFile("temp_2.csv"), temp_selfHelpFile("temp_3.csv");
  
    cout<<"Select Category from which you want to borrow book(s)."<<endl;
    cout<<"1. Novels."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cin>>cat;

    if(!file_1.is_open() && !file_2.is_open() && !file_3.is_open() ){
        if(!temp_novelFile.is_open() && !temp_academicsFile.is_open() && temp_selfHelpFile.is_open()){
            cout<<"Error. Something wrong with file(s) opening."<<endl;
        }
    }else{
        switch(cat){
            case 1:
                cout<<"Enter book title."<<endl;
                getline(cin, borrow_book_title);

                while(getline(file_1, str)){
                    stringstream file_string(str);
                    string title, author, quantity_in_str;

                    getline(file_string, title, ',');
                    getline(file_string, author, ',');
                    getline(file_string, quantity_in_str, ',');

                    int quantity = stoi(quantity_in_str);

                    if(title == borrow_book_title){
                        required_book = true;
                        if(required_book == true && quantity > 0){
                            cout<<"Sucessfully borrowed the book."<<endl;
                            quantity--;
                        }else if(quantity == 0){
                            cout<<"Book currently not avaible in library."<<endl;
                    }

                        if(required_book == false){
                            cout<<"Book Not Found."<<endl;
                        }

                        temp_novelFile<<title<<","<<author<<","<<quantity;
                    }

                }

                file_1.close();
                temp_novelFile.close();

                remove(a);
                rename("temp_novelFile.csv", a);
            break;

            case 2:
                cout<<"Enter book title."<<endl;
                getline(cin, borrow_book_title);

                while(getline(file_2, str)){
                    stringstream file_string(str);
                    string title, author, quantity_in_str;

                    getline(file_string, title, ',');
                    getline(file_string, author, ',');
                    getline(file_string, quantity_in_str, ',');

                    int quantity = stoi(quantity_in_str);

                    if(title == borrow_book_title){
                        required_book = true;
                        if(required_book == true && quantity > 0){
                            cout<<"Sucessfully borrowed the book."<<endl;
                            quantity--;
                        }else if(quantity == 0){
                            cout<<"Book currently not avaible in library."<<endl;
                    }

                        if(required_book == false){
                            cout<<"Book Not Found."<<endl;
                        }

                        temp_academicsFile<<title<<","<<author<<","<<quantity;
                    }

                }

                file_2.close();
                temp_academicsFile.close();
            break;

            case 3:
                cout<<"Enter book title."<<endl;
                getline(cin, borrow_book_title);

                while(getline(file_3, str)){
                    stringstream file_string(str);
                    string title, author, quantity_in_str;

                    getline(file_string, title, ',');
                    getline(file_string, author, ',');
                    getline(file_string, quantity_in_str, ',');

                    int quantity = stoi(quantity_in_str);

                    if(title == borrow_book_title){
                        required_book = true;
                        if(required_book == true && quantity > 0){
                            cout<<"Sucessfully borrowed the book."<<endl;
                            quantity--;
                        }else if(quantity == 0){
                            cout<<"Book currently not avaible in library."<<endl;
                    }

                        if(required_book == false){
                            cout<<"Book Not Found."<<endl;
                        }

                        temp_selfHelpFile<<title<<","<<author<<","<<quantity;
                    }

                }

                file_3.close();
                temp_selfHelpFile.close();
            break;

            default:
                cout<<"Invalid category."<<endl;
            break;
        }  
    }
}
