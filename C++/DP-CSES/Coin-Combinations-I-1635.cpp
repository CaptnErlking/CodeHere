#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i] meaning the number of ways to construct i amount
// transition : dp[i] = dp[i - c[0]] + dp[i - c[1]]... dp[i - c[n]]
//              Basically there is 1 way to reach from d[i - c[k]] to reach
//              "i", so basically we are adding all the values of k ;)

int coinWays(int n, int i, vector<int> &c, vector<int> &dp) {
    if (i < 0) return 0; 
    if (i == 0) return 1;
    if (dp[i] != -1)  return dp[i]; 
    dp[i] = 0; 
    for (int k = 0; k < n; k++) {
        dp[i] = (dp[i] + coinWays(n, i - c[k], c, dp)) % MOD; 
    }   
    return dp[i]; 
}

int main() {
    int n, x; 
    cin >> n >> x;  
    vector<int> c(n); 
    for (int i = 0; i < n; i++) cin >> c[i]; 
    vector<int> dp(x + 1, -1); 
    cout << coinWays(n, x, c, dp) << endl; 

}