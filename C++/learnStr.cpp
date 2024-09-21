#include<iostream>
using namespace std;
int main(){
    
    /*
    string name;
    cout << "Enter you name: ";
    cin >> name ; 

    cout << "Your name is " << name ;
    */

    const int size = 100; 
    char line[size];
    cout << endl << "OK now Enter a line : " ; 
    cin.getline(line,size);

    cout << "Here is what you just wrote : " << endl 
    << line ;
}