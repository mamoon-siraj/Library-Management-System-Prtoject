#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>

using namespace std;

void menu();
void display_books();
void add_books();


int main(){
    
    cout<<"Welcome to Library."<<endl;

    menu();

    return 0;
}

void menu(){

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

    cout<<"Enter the category."<<endl;
    cout<<"1. Novel."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cin>>cat;

    char exit = 'y';

    do
    {
        ofstream file_1("Novels.csv", ios::app), file_2("academicbooks.csv", ios::app), file_3("SelfHelpbooks.csv", ios::app);

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
    cout<<"Want to add another one?(y/n)"<<endl;
    cin>>exit;
    
        
    } while (exit == 'Y' || exit == 'y');
    
}   

void novel_category(){
    ifstream file_1("Novels.csv");

    if(file_1.is_open()) {
        string str;
        while (getline(file_1, str)) { 
            cout << str <<endl; 
        }

            file_1.close();
        }else{
            cout <<"Error could not open the file."<<endl; 
        }
}

void academic_category(){
    ifstream file_2("academicbooks.csv");

    if(file_2.is_open()) {
        string str;
        while (getline(file_2, str)) { 
            cout << str <<endl; 
        }

            file_2.close();
    }else{
            cout <<"Error could not open the file."<<endl; 
    }
}

void self_help_book_category(){
    ifstream file_3("selfHelpbooks.csv");

    if(file_3.is_open()) {
        string str;
        while (getline(file_3, str)) { 
            cout << str <<endl; 
        }

            file_3.close();
    }else{
            cout <<"Error could not open the file."<<endl; 
    }
}

void all_category(){
    ifstream file_1("Novels.csv");

    if(file_1.is_open()) {
        string str;
        while (getline(file_1, str)) { 
            cout << str <<endl; 
        }

            file_1.close();
    }else{
            cout <<"Error could not open the file."<<endl; 
    }

    ifstream file_2("academicbooks.csv");

    if(file_2.is_open()) {
        string str;
        while (getline(file_2, str)) { 
            cout << str <<endl; 
        }

            file_2.close();
    }else{
            cout <<"Error could not open the file."<<endl; 
    }

    ifstream file_3("selfHelpbooks.csv");

    if(file_3.is_open()) {
        string str;
        while (getline(file_3, str)) { 
            cout << str <<endl; 
        }

            file_3.close();
    }else{
            cout <<"Error could not open the file."<<endl; 
    }
}

void display_books(){
    
    int cat;
   
    cout<<"Enter the category."<<endl;
    cout<<"1. Novel."<<endl;
    cout<<"2. Academics."<<endl;
    cout<<"3. Self-help."<<endl;
    cout<<"4. To view all categories simaltaneously."<<endl;
    cin>>cat;

    switch (cat)
    {
        case 1:
            novel_category();
        break;

        case 2:
            academic_category();
        break;

        case 3:
            self_help_book_category();    
        break;

        case 4:
            all_category();
        default:
            cout<<"Select Valid Category."<<endl;
        break;
    }

}

