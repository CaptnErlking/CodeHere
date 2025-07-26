#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7; 

// state : dp[i][j] meaning edits till i-th char in first string and
//          j-th char in second string
// transition : if A[i] == B[j] -> dp[i][j] == dp[i + 1][j + 1] 
//              if inserted in A -> 1 + dp[i][j + 1]
//              if inserted in B -> 1 + dp[i + 1][j]
//              if deleted in A -> 1 + dp[i + 1][j]
//              if deleted in B -> 1 + dp[i][j + 1]
//              that means -> dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1])

int solve(int i, int j, int n, int m, string &a, string &b, vector<vector<int>> &dp) {
    if (i == n) return m - j; 
    if (j == m) return n - i; 
    if (dp[i][j] != -1) return dp[i][j]; 
    if (a[i] == b[j]) dp[i][j] = solve(i + 1, j + 1, n, m, a, b, dp); 
    else dp[i][j] = min(1 + solve(i + 1, j + 1, n, m, a, b, dp),    // replace
                1 + min(solve(i + 1, j, n, m, a, b, dp),            // dA iB
                        solve(i, j + 1, n, m, a, b, dp)));          // iA dB
    return dp[i][j]; 
}

int main() {
    string a;
    string b; 
    cin >> a; 
    cin >> b; 
    int n = a.size();
    int m = b.size(); 
    vector<vector<int>>  dp(n, vector<int> (m, -1)); 
    cout << solve(0, 0, n, m, a, b, dp) << endl;
}