#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i][j] meaning number of ways to reach grid[i][j] without hitting
//                  any trap; 
// transition : dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
//                  number of ways to reach upper square + left square
/*
int ways(int i, int j, int n, vector<string> &grid, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) return 0; 
    if (grid[i][j] == '*') return 0; 
    if (i == 0 && j == 0)  return 1; 
    if (dp[i][j] != -1) return dp[i][j]; 
    int up = ways(i - 1, j, n, grid, dp) % MOD; 
    int down = ways(i, j - 1, n, grid, dp) % MOD; 
    dp[i][j] = (up + down) % MOD; 
    return dp[i][j]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<string> grid(n); 
    for (int i = 0; i < n; i++) cin >> grid[i]; 
    vector<vector<int>> dp(n, vector<int> (n, -1)); 
    cout << ways(n - 1, n - 1, n, grid, dp) << endl;
}
*/

int main() {
    int n; 
    cin >> n; 
    vector<string> grid(n); 
    for (int i = 0; i < n; i++) cin >> grid[i]; 
    vector<vector<int>> dp(n, vector<int> (n, 0)); 
    int ans = 0; 
    dp[0][0] = 1; 
    if (grid[0][0] == '*') goto print_ans; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int up = ((i - 1) < 0) ? 0 : dp[i - 1][j] % MOD; 
            int down = ((j - 1) < 0) ? 0 : dp[i][j - 1] % MOD; 
            dp[i][j] += (grid[i][j] == '*') ? 0 : ((up + down) % MOD); 
        }
    }
    ans = dp[n - 1][n - 1]; 
    print_ans : 
    cout << ans << endl;  
}