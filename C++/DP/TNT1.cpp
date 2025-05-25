#include<bits/stdc++.h>
using namespace std; 

// state : dp[i] meaning maximum sum till ith index
// transition : dp[i] = max(take, notTake) 
//                      take = a[i] + solve(i + 2, n, a, dp); skipped next since included curr
//                      notTake = 0 + solve(i + 1, n, a, dp); took next since skipped curr

int solve(int i, int n, vector<int> &a, vector<int> &dp) {
    if (i >= n) return 0; 
    if (dp[i] != -1) return dp[i]; 
    int take = a[i] + solve(i + 2, n, a, dp);
    int notTake = 0 + solve(i + 1, n, a, dp); 
    dp[i] = max(take, notTake);  
    return dp[i]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<int> v(n, 0); 
    vector<int> dp(n + 1, -1); 
    for (int i = 0; i < n; i++) cin >> v[i]; 
    cout << solve(0, n, v, dp) << endl; 
}