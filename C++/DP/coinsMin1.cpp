#include<bits/stdc++.h>
using namespace std; 
#define inf INT_MAX

int minCoin (int n, int x, vector<int> &c, vector<int> &dp) {
    if (x < 0) return inf; 
    if (x == 0) return 0; 
    if (dp[x] != -1) return dp[x]; 
    int res = inf; 
    for (int i = 0; i < n; i++) {
        int sub = minCoin(n, x - c[i], c, dp); 
        if (sub != inf) res = min(res, sub + 1); 
    }
    dp[x] = res; 
    return dp[x]; 
}

int main() {
    int n, x; 
    cin >> n >> x; 
    vector<int> c(n); 
    vector<int> dp(x + 1, -1); 
    for (int i = 0; i < n; i++) cin >> c[i]; 
    cout << minCoin(n, x, c, dp) << endl; 
}