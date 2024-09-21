#include<iostream>
using namespace std;
bool isSet(int n, int k){
    n>>=(k-1);
    if(n&1) return true;
    return false;
}
int main(){
    cout << "Enter a number : " ; 
    int n ;
    cin >> n ;
    cout << "Enter a position : " ; 
    int k ; 
    cin >> k ;
    cout << "The bit at " << k << " position is " ;
    isSet(n,k) ? (cout << "set" << endl ) : (cout << " not set" << endl ) ;
}