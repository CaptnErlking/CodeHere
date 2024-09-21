#include<iostream>
using namespace std;
void one2n(int n){
    if (n==0) return;
    cout << n << endl ; 
    one2n(n-1);
}
int main() {
    cout << "Enter a number : " ;
    int n ; 
    cin >> n ;
    one2n(n);
}