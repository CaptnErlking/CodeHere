#include<iostream>
#include<string>
using namespace std;
void subset(string s ,string curr="" ,int i=0) {
    if (i==s.length()){
        cout << curr << " " ; 
        return ;   
    }
    subset(s,curr,i+1);
    subset(s,curr+s[i],i+1);
}
int main() {
    cout << "Enter a string : " ;
    string s ; 
    cin >> s ;
    cout << "The subsets of this string are : " << endl ;   
    subset(s) ;
}