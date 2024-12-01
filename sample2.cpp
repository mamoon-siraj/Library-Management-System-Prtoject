#include<iostream>
#include<string>
using namespace std;

int main(){
    
    string sentance = "I am Anas";
    
    size_t first_space = sentance.find(' ');
    size_t second_space = sentance.find(' ',first_space+1);

    string verb = sentance.substr(first_space, second_space);

    cout<<verb<<endl;

    return 0;
}