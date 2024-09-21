#include<iostream>
using namespace std;
int sumOfDig(int n){
    if (n/10==0) return n%10 ;
    return n%10 + sumOfDig(n/10);
}
int tillSingle(int n){
    if (n/10==0) return n;
    return tillSingle(sumOfDig(n));
}
int main() {
    cout << "Enter a number to get the sum of it's Digits : " ;
    int n ;
    cin >> n ;
    cout << "The sum of it's Digits are : " << tillSingle(n) ;
}