#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    const char *a = "Novels.csv";
    const char *b = "academicbooks.csv";
    const char *c = "SelfHelpbooks.csv";

    ifstream file_1(a), file_2(b), file_3(c);

    if(!file_1.is_open()){
        cout<<"Error in open file 1."<<endl;
    }
    if(!file_2.is_open()){
        cout<<"Error in open file 2."<<endl;
    }
    if(!file_3.is_open()){
        cout<<"Error in open file 2."<<endl;
    }

     
}