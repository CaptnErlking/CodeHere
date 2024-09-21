#include<iostream>
using namespace std;
int sumofn(int n){
    if (n<=1) return 1;
    return n+sumofn(n-1);
}
int main() {
    cout << "Enter a number : " ;
    int n ;
    cin >> n ;
    cout << "Sum of First " << n << " natural numbers is : " << sumofn(n) ;
}