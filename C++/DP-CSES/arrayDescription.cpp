#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i][j] meaning number of ways to fill the blanks till ith position
//          assuming the current element is j
// transition : dp[i][j] = dp[i - 1][x - 1] + dp[i - 1][x] + dp[i - 1][x + 1]
//          since difference can be atmost one -_-
// base case : if the frist element is 0 there's just one way, else
//              0 ways except dp[i][what ever the number is] = 1

int solve (int i, int j, int n, int m, vector<int> &arr, vector<vector<int>> &dp) {
    if (j < 1 || j > m) return 0; 
    if (dp[i][j] != -1) return dp[i][j]; 
    if (i == 0) { 
        if (arr[i] == 0) return dp[i][j] = 1; 
        else if (j == arr[i]) return dp[i][j] = 1; 
        return dp[i][j] = 0; 
    } 
    if (arr[i] != 0 && arr[i] != j) return dp[i][j] = 0; 
    dp[i][j] = solve(i - 1, j - 1, n, m, arr, dp); 
    dp[i][j] = (dp[i][j] + solve(i - 1, j, n, m, arr, dp)) % MOD; 
    dp[i][j] = (dp[i][j] + solve(i - 1, j + 1, n, m, arr, dp)) % MOD; 
    return dp[i][j];
}

int main() {
    int n, m; 
    cin >> n >> m; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<vector<int>> dp(n, vector<int> (m + 2, -1)); 
    int ans = 0; 
    for (int i = 1; i <= m; i++) ans = (ans + solve(n - 1, i, n, m, arr, dp)) % MOD; 
    cout << ans << endl;  
}
