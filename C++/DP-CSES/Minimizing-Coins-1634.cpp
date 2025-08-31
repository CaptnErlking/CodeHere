#include<bits/stdc++.h>
using namespace std; 
#define inf INT_MAX
const int MOD = 1e9 + 7;

// state : dp[i] meaning the number of coins required to construct i
// transition : dp[i] = min(dp[i - c[0]], dp[i - c[1]].... dp[i - c[n]])

int minCoin(int n, int x, vector<int> &c, vector<int> &dp) {
    if (x < 0) return 1e9; 
    if (x == 0) return 0; 
    if (dp[x] != -1) return dp[x]; 
    int res = 1e9; 
    for (int i = 0; i < n; i++) {
        int sub = minCoin(n, x - c[i], c, dp); 
        res = min(res, sub + 1); 
    }
    dp[x] = res;
    return dp[x];
}

int main() {
    int n, x; 
    cin >> n >> x; 
    vector<int> c(n); 
    for (int i = 0; i < n; i++) cin >> c[i]; 
    vector<int> dp(x + 1, -1); 
    int ans = minCoin(n, x, c, dp); 
    cout << (ans >= 1e9 ? -1 : ans) << endl;
}
