#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7; 

// state : dp[i][j] minimum cuts to make squares till (i, j) position
// transition : if i == j -> dp[i][j] = 0
//              dp[i][j] = 1 + (min(dp[i][k] + dp[i][j - k]),
//                              min(dp[k][j] + dp[i - k][j]))

/*
int solve(int i, int j, vector<vector<int>> &dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j]; 
    int best = INT_MAX;
    for (int k = 1; k < i; k++) 
    best = min(best, 1 + solve(k, j, dp) + solve(i - k, j, dp));
    for (int k = 1; k < j; k++) 
    best = min(best, 1 + solve(i, k, dp) + solve(i, j - k, dp));
    dp[i][j] = best;
    return dp[i][j]; 
}
*/

int main() {
    int n, m; 
    cin >> n >> m; 
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1)); 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (i == j) {
                dp[i][j] = 0;
            } else {
                int best = INT_MAX;
                for(int k = 1; k <= i/2; ++k)
                    best = min(best, dp[k][j] + dp[i-k][j] + 1);
                for(int k = 1; k <= j/2; ++k)
                    best = min(best, dp[i][k] + dp[i][j-k] + 1);
                dp[i][j] = best;
            }
        }
    }
    cout << dp[n][m] << endl;
}