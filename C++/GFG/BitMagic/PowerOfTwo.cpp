#include<iostream>
using namespace std; 
bool isPow2(int n){
    if (n==0) return false;
    return ((n&(n-1))==0);
}
int main(){
    cout << "Enter a number : " ;
    int n ;
    cin >> n ;
    isPow2(n) ? cout << "It is a power of two :)" : cout << "It is not a power of two :(" ;
}