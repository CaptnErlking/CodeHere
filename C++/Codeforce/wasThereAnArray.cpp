#include<iostream>
#include<vector>
using namespace std ;

bool wasArray(vector<int> &v, int n) {
    bool pprev, prev, curr; 
    bool pprevE; 
    if (v[0] == 0 && v[1] == 1) {
        pprev = 1; 
        prev = 0; 
        curr = 0; 
    }
    else if (v[0] == 0 && v[1] == 0){
        pprev = 0;
        prev = 0; 
        curr = 0; 
    }
    else {
        pprev = prev = curr = 0; 
    }
    for (int i = 1; i < n; i++) { 
        if (i > 1) pprevE = v[i-2]; 
        if (v[i] == 0) {
            if (prev == curr) {
                pprev = prev; 
                curr = !curr;     
            }
            else {
                pprev = prev; 
                prev = curr; 
            }
        }
        else {
            if (prev != curr) {
                if (pprevE == 1) {
                    return false; 
                }
                else if (pprev == 0 && pprev == 1) {
                    return false; 
                }
            } 
        }
    }
    return true; 
}

int main() {
    int t, n; 
    cin >> t; 
    while (t--) {
        cin >> n; 
        vector<int> v(n); 
        for (int i = 0; i < n - 2; i++) {
            cin >> v[i]; 
        }
        if (wasArray(v, n)) {
            cout << "YES" << endl; 
        }
        else cout << "NO" << endl; 
    }
}