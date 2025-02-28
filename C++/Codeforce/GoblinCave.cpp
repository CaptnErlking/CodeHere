#include <bits/stdc++.h>
using namespace std; 

long long goblin(string str, int n) {
    if (n < 3) return 0; 
    long long dc = 0, uc = 0; 
    for (char c : str) {
        if (c == '-') dc++; 
        else uc++; 
    }
    if (dc < 2 || uc == 0) return 0; 

    return (dc / 2) * (dc - dc / 2) * uc; 
}

int main() {
    int t, n; 
    cin >> t; 
    while (t--) {
        cin >> n; 
        string str; 
        cin >> str; 
        cout << goblin(str, n) << endl; 
    }
}
