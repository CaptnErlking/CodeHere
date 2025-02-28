#include<bits/stdc++.h>
using namespace std; 

int mathing(vector<int> &board, int n, int k) {
    int ans = 0; 
    sort(board.begin(), board.end()); 
    unordered_map<int, int> m; 
    for (int i = n - 1; i >= 0; i--) {
        int curr = k - board[i]; 
        if (curr > board[n - 1]) break; 
        else m[curr]++; 
    }
    for (int i = 0; i < n; i++) {
        if (m.find(board[i]) != m.end()) {
            m[board[i]]--; 
            ans++; 
            if (m[board[i]] == 0) m.erase(board[i]); 
        }
    }
    return ans / 2; 
}

int main () {
    int t, n, k; ; 
    cin >> t; 
    while (t--) {
        cin >> n >> k; 
        vector<int> board; 
        for (int i = 0; i < n; i++) {
            int x; 
            cin >> x; 
            board.push_back(x); 
        }
        cout << mathing(board, n, k) << endl; 
    }
}