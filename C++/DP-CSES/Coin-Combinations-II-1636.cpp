#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7; 

// state : dp[i][x] meaning using till ith coin we have made x amount
// transition : dp[i][x] = take + notTake
//                          take = dp[i][x - c[i]]
//                          notTake = dp[i + 1][x]
/* 
int coinWays(int i, int x, int n, vector<int> &c, vector<vector<int>> &dp) {
    if (x < 0) return 0; 
    if (i == n) return 0; 
    if (x == 0) return 1;
    if (dp[i][x] != -1) return dp[i][x]; 
    int take = coinWays(i, x - c[i], n, c, dp) % MOD; 
    int notTake = coinWays(i + 1, x, n, c, dp) % MOD; 
    dp[i][x] = (take + notTake) % MOD; 
    return dp[i][x]; 
}

int main() {
    int n, x; 
    cin >> n >> x; 
    vector<int> coins(n, 0); 
    for (int i = 0; i < n; i++) cin >> coins[i]; 
    vector<vector<int>> dp(n + 1, vector<int> (x + 1, -1)); 
    cout << coinWays(0, x, n, coins, dp) << endl; 
}
*/

int main() {
    int n, x; 
    cin >> n >> x; 
    vector<int> coins(n, 0); 
    for (int i = 0; i < n; i++) cin >> coins[i]; 
    vector<int> dp(x + 1, 0);
    // trying buttom-up approach :)
    dp[0] = 1;  
    for (int i = 0; i < n; i++) {
        for (int sum = coins[i]; sum <= x; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coins[i]]) % MOD; 
        }
    }
    cout << dp[x] << endl; 
}