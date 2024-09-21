#include<iostream>
#include<string>
using namespace std;
bool isPallindrome(string &s,int k){
    if (k==s.size()/2 && (s[k]==s[s.size()-1-k])) return true;
    if (s[k]==s[s.size()-1-k]) return isPallindrome(s,k+1);
    return false;
}
int main() {
    cout << "Enter a string : " ;
    string s ;
    cin >> s ;
    isPallindrome(s,0) ? cout << "Its a Pallindrome :)" : cout << "Its not a Palindrome :(" ;
}