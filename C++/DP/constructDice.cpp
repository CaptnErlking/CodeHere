#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i] meaning the number of ways to make n using 1 - 6
// transition : d[i] = dp[i - 1] + dp[i - 2] ....... dp[i - 6] 
//   -> This is done becuase we have 1 ways to reach from i, 
//      and 1 way to reach from i - 2 to i and so on...

int ways(int n, vector<int> &dp) {
    if (n < 0) return 0; 
    if (n == 0) return 1; 
    if (dp[n] != -1) return dp[n]; 
    dp[n] = 0; 
    for (int i = 1; i <= 6; i++) dp[n] = (dp[n] + ways(n - i, dp)) % MOD; 
    return dp[n]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<int> dp(n + 1, -1); 
    cout << ways(n, dp) << endl; 
}