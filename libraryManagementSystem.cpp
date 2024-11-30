#include<iostream>
using namespace std;

void librarian_menu();
void student_menu();

int main(){

    int designation;
    
    cout<<"Please select the apprpriate by pressing number."<<endl;
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
    default:
        cout<<"Invalid Designation"<<endl;
        break;
    }

}