#include<bits/stdc++.h>
using namespace std; 

bool cowGame(vector<vector<int>> &cows, int n, int m, vector<int> & result) {
    int mini = 2001; 
    int maxi = -1; 
    unordered_map<int, int> map; 
    for (int i = 0; i < n; i++) {
        mini = min(mini, cows[i][0]); 
        maxi = max(maxi, cows[i][0]); 
        map[cows[i][0]] = i;
    }
    // cout << maxi << " " << mini << endl; 
    if (mini != 0 || maxi != n - 1) {
        // cout << "first " << endl; 
        return false; 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (cows[i][j] != (cows[i][j - 1] + n)) {
                // cout << "second " << endl; 
                return false;  
            }
        }
    }
    for (int i = 0; i < n; i++) {
        result.push_back(map[i] + 1); 
    }
    return true; 
}

int main() {
    int t, n, m; 
    cin >> t; 
    while (t--) {
        cin >> n >> m ; 
        vector<vector<int>> cows; 
        for (int i = 0; i < n; i++) {
            vector<int> temp; 
            for (int j = 0; j < m; j++) {
                int x; 
                cin >> x; 
                temp.push_back(x); 
            }
            sort(temp.begin(), temp.end()); 
            cows.push_back(temp); 
        }
        vector<int> result; 
        if (cowGame(cows, n, m, result)) {
            for (auto it : result) {
                cout << it << " "; 
            }
            cout << endl; 
        }
        else cout << -1 << endl; 
        
    }
}
