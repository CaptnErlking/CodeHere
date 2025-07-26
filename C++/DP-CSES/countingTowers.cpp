#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7; 

// state : dp[i][type] meaning the number of ways to fill tower till ith row
//          with a specific type
//                  type 0 means two 1x1 blocks
//                  type 1 means one 1x2 block
// transition : dp[i][0] = (both closing) + 2 * (either one closing) + (both open)
//                      dp[i + 1][0] + dp[i + 1][1] + 3 * dp[i + 1][0]
//              dp[i][1] = (closing) + (open)
//                      2 * dp[i + 1][1] + dp[i + 1][0]

/*
int solve (int i, int type, int n, vector<vector<int>> &dp) {
    if (dp[i][type] != -1) return dp[i][type]; 
    if (i == n - 1) return dp[i][type] = 1;
    if (type) {
        dp[i][type] = (2LL * solve(i + 1, type, n, dp) % MOD + solve(i + 1, !type, n, dp)) % MOD; // fixed here
    } else {
        dp[i][type] = (4LL * solve(i + 1, type, n, dp) % MOD + solve(i + 1, !type, n, dp)) % MOD; // fixed here
    }
    return dp[i][type];
}
*/

int main() {
    int t; 
    cin >> t; 
    vector<int> qs(t);
    int Nmax = 0;
    for(int i = 0; i < t; i++){
        cin >> qs[i];
        Nmax = max(Nmax, qs[i]);
    }
    vector<int> S(Nmax+1), M(Nmax+1), ans(Nmax+1);
    S[1] = 1;
    M[1] = 1;
    ans[1] = (S[1] + M[1]) % MOD; 
    for(int k = 2; k <= Nmax; k++){
        long long s = (4LL * S[k-1] + M[k-1]) % MOD;
        long long m = (S[k-1] + 2LL * M[k-1]) % MOD;
        S[k] = int(s);
        M[k] = int(m);
        ans[k] = int((s + m) % MOD);
    }
    for(int n: qs){
        cout << ans[n] << "\n";
    }
}