#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

int solve (int i, int type, int n, vector<vector<int>> &dp) {
    if (dp[i][type] != -1) return dp[i][type]; 
    if (i == n - 1) return 1; 
    if (type) {
        dp[i][type] = 2 * (solve(i + 1, type, n, dp) * 1LL) + solve(i + 1, !type, n, dp) * 1LL; 
    } else {
        dp[i][type] = 4 * (solve(i + 1, type, n, dp) * 1LL) + solve(i + 1, !type, n, dp) * 1LL; 
    }
    return dp[i][type]; 
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
#endif

	int t; 
    cin >> t; 
    while (t--) {
        int n; 
        cin >> n; 
        vector<vector<int>> dp(n, vector<int> (2, -1)); 
        cout << solve(0, 0, n, dp) + solve(0, 1, n, dp) << endl; 
    }
}