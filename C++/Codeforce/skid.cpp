#include<iostream>
using namespace std; 

void skid(string str) {
    for (int i = 1; i < str.size(); i++) {
        if (str[i] == str[i-1]) {
            cout << 1 << endl; 
            return;
        }
    }
    cout << str.size() << endl; 
}

int main () {
    int t; 
    cin >> t; 
    while(t--) {
        string str;
        cin >> str; 
        skid(str) ; 
    }
}