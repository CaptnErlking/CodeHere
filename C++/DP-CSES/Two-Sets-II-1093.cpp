#include<bits/stdc++.h>
using namespace std; 
const int mod = 1e9 + 7; 

// state : dp[i][x] meaning number of ways to create x amount till ith index
// transition : dp[i][x] = take + notTake
//                          take = dp[i][x - i]
//                          notTake = dp[i + 1][x]

int sumTill(int n) {
    int ans = 0;
    do ans += n; while (n--);
    return ans;
}

int solve(int i, int x, int n, vector<vector<int>> &dp) {
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (i == n) return 0;
    if (dp[i][x] != -1) return dp[i][x];
    int take = solve(i + 1, x - (i + 1), n, dp);
    int notTake = solve(i + 1, x, n, dp);
    dp[i][x] = (take + notTake) % mod;
    return dp[i][x];
}

int main() {
    int n;
    cin >> n;
    int target = sumTill(n);
    if (target % 2) { cout << 0 << endl; return 0; }
    target /= 2;
    vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
    long long ans = solve(0, target, n, dp);
    cout << (ans * 500000004LL) % mod << endl;
}