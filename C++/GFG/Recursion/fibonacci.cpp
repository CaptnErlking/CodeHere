#include<iostream>
using namespace std; 
int fibonacci(int n){
    if (n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main() {
    cout << "Enter a number : " ;
    int n ;
    cin >> n ;
    cout << "The n'th number in then Fibonacci sequence is : " << endl ;
    cout << fibonacci(n-1) ; 
}