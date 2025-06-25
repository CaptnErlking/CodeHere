#include<bits/stdc++.h>
using namespace std; 

#define inf INT_MAX

// state : dp[i][j] meaning shortest path from a[i][j] to destination
// transition : dp[i][j] = a[i][j] + min(f(i + 1, j), f(i, j + 1))

int solve(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<int>> &dp) {
    if (i >= n || i < 0 || j >= m || j < 0)  return inf; 
    if (i == n - 1 && j == m - 1) return a[i][j]; 
    if (dp[i][j] != -1) 
        return dp[i][j]; 
    dp[i][j] = a[i][j] + min(solve(i + 1, j, n, m, a, dp), solve(i, j + 1, n, m, a, dp)); 
    return dp[i][j]; 
}

int main() {
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> a(n, vector<int>(m, 0)); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j]; 

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); 
    cout << solve(0, 0, n, m, a, dp) << endl;       
}