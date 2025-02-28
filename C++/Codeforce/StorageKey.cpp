#include<bits/stdc++.h>
using namespace std; 

void key(int n, int x) {
    int zor = 0; 
    for (int i = 0; i < n; i++) {
        if ((i & x) != i) {
            while (i < n - 1) {
                cout << 0 << " " ; 
                i++; 
            }
            cout << x << endl; 
            return; 
        } else {
            zor |= i; 
            if (i == n - 1) {
                if (zor == x ) cout << i << endl ; 
                else cout << x << endl; 
                return; 
            }
            cout << i << " " ; 
        }
    }
}

int main() {
    int t, n, x; 
    cin >> t;
    while (t--) {
        cin >> n >> x; 
        key(n, x); 
    }
}
