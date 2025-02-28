#include<bits/stdc++.h>
using namespace std; 
int main () {
    int t, n, k, p; 
    cin >> t; 
    while (t--) {
        cin >> n >> k >> p; 
        k = abs(k); 
        p = abs(p);
        int count = (k % p == 0) ? (k / p) : (k / p + 1);    
        if (count > n) {
            cout << -1 << endl; 
        }
        else {
            cout << count << endl;     
        }
    }
}