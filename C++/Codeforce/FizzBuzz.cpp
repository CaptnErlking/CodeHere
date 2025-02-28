#include<bits/stdc++.h>
using namespace std; 

long long fizzBuzz(long long n) {
    int comm = 0; 
    int carry = (n % 15 > 2) ? 3 : (n % 15 + 1); 
    comm = (n / 15) * 3 + carry;
    return comm;  
}

int main() {
    int t;
    long long n; 
    cin >> t; 
    while (t--) {
        cin >> n; 
        cout << fizzBuzz(n) << endl; 
    }
}