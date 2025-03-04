#include<bits/stdc++.h>
using namespace std; 

bool wasArray(vector<int> x, int n) {
    n = n - 2; 
    if (n < 3) return true; 
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1; 
        int k = j + 1 ;
        if (x[i] == 1 && x[j] == 0 && x[k] == 1) {
            return false;
        }
    }
    return true; 
}

int main() {
    int t, n; 
    cin >> t; 
    while (t--) {
        cin >> n; 
        vector<int> x(n-2); 
        for (int i = 0; i < n - 2; i++) cin >> x[i]; 
        if (wasArray(x, n))  {
            cout << "YES" << endl; 
        }   
        else {
            cout << "NO" << endl; 
        }
    }
}