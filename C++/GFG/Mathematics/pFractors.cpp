#include<iostream>
using namespace std;
void FactorPrinter(int n){
    if (n<=1) return;
    while (n%2==0){
        cout << "2 " ; n/=2 ;
    }
    while (n%3==0){
        cout << "3 " ; n/=3 ;
    }
    for (int i=5; i*i<=n ; i+=6){
        while (n%i==0){
            cout << i << " " ; n/=i;
        }
        while (n%(i+2)==0){
            cout << i+2 << " " ; n/=(i+2);
        }
    }
    if (n>3) cout << n << " " ;
} 
int main() {
    cout << "Enter a number to see it's prime factors : " ;
    int number;
    cin >> number;
    FactorPrinter(number);
}   