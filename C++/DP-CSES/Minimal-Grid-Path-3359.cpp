#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i][j][d] meaning best first distinct character from d direction
// transition : if (m[i + 1][j] != m[i][j + 1]) 
//                  dp[i][j][0] = m[i + 1][j]
//                  dp[i][j][1] = m[i][j + 1]
//              right -> dp[i][j][1] = min(dp[i][j + 1][0], dp[i][j + 1][1]); 
//              down  -> dp[i][j][0] = min(dp[i + 1][j][0], dp[i + 1][j][1]); 

/*
int solve(int i, int j, int d, vector<string> &m, vector<vector<vector<int>>> &dp, int n) {
    if (i == n || j == n) {
        dp[i][j][d] = INT_MAX;
        dp[i][j][!d] = INT_MAX;
        return dp[i][j][d]; 
    }
    if (dp[i][j][d] != -1) return dp[i][j][d]; 
    if (i < n - 1 && j < n - 1) {
        if (m[i + 1][j] != m[i][j + 1]) {
            solve(i, j + 1, 1, m, dp, n);
            solve(i + 1, j, 0, m, dp, n);
            dp[i][j][0] = m[i + 1][j]; 
            dp[i][j][1] = m[i][j + 1]; 
        } else {
            dp[i][j][0] = min(solve(i + 1, j, 0, m, dp, n), solve(i + 1, j, 1, m, dp, n));
            dp[i][j][1] = min(solve(i, j + 1, 0, m, dp, n), solve(i, j + 1, 1, m, dp, n));
        }
    } else {
        if (i == n - 1 && j == n - 1) {
            dp[i][j][0] = dp[i][j][1] = INT_MAX; 
        } else if (i == n - 1) {
            dp[i][j][0] = INT_MAX; 
            dp[i][j][1] = m[i][j + 1]; 
        } else {
            dp[i][j][0] = m[i + 1][j]; 
            dp[i][j][1] = INT_MAX;
        }
    } 
    return dp[i][j][d]; 
} 
*/
/*
int main() { 
    int n;  
    cin >> n;  
    vector<string> m(n); 
    for (int i = 0; i < n; i++) cin >> m[i]; 
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1))); 
    dp[n][n][0] = dp[n][n][1] = INT_MAX; 
    for (int i = 0; i < n; i++) dp[i][n][0] = dp[i][n][1] = INT_MAX;
    for (int i = 0; i < n; i++) dp[n][i][0] = dp[n][i][1] = INT_MAX;
    for (int i = 0; i < n; i++) {
        dp[n - 1][i][1] = i != n - 1 ? m[n - 1][i + 1] : INT_MAX; 
        dp[n - 1][i][0] = INT_MAX; 
    }
    for (int i = 0; i < n; i++) {
        dp[i][n - 1][0] = i != n - 1 ? m[i + 1][n - 1] : INT_MAX; 
        dp[i][n - 1][1] = INT_MAX; 
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            if (m[i + 1][j] != m[i][j + 1]) {
                dp[i][j][0] = m[i + 1][j]; 
                dp[i][j][1] = m[i][j + 1]; 
            } 
            else {
                dp[i][j][0] = min(dp[i + 1][j][0], dp[i + 1][j][1]);
                dp[i][j][1] = min(dp[i][j + 1][0], dp[i][j + 1][1]); 
            }
        }
    }
    string ans = "";
    int i = 0; 
    int j = 0; 
    while (i < n && j < n) { 
        ans += m[i][j]; 
        if (dp[i][j][0] < dp[i][j][1]) i++; 
        else j++; 
    } 
    cout << ans << endl; 
}
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    if(!(cin>>n)) return 0;
    vector<string> m(n);
    for(int i=0;i<n;i++) cin>>m[i];
    string ans;
    ans.push_back(m[0][0]);
    if(n==1){ cout<<ans<<"\n"; return 0; }
    vector<int> cur;
    cur.push_back(0);
    vector<int> seen(n*n,0);
    int stamp = 1;
    for(int step=1; step<=2*n-2; ++step){
        char best = '{';
        vector<int> cand;
        for(int idx: cur){
            int i = idx / n, j = idx % n;
            if(i+1 < n){
                int ni = (i+1)*n + j;
                if(seen[ni] != stamp){
                    seen[ni] = stamp;
                    cand.push_back(ni);
                    if(m[i+1][j] < best) best = m[i+1][j];
                }
            }
            if(j+1 < n){
                int ni = i*n + (j+1);
                if(seen[ni] != stamp){
                    seen[ni] = stamp;
                    cand.push_back(ni);
                    if(m[i][j+1] < best) best = m[i][j+1];
                }
            }
        }
        ++stamp;
        vector<int> nxt;
        for(int idx : cand) if(m[idx/n][idx%n] == best) nxt.push_back(idx);
        ans.push_back(best);
        cur.swap(nxt);
    }
    cout<<ans<<"\n";
    return 0;
}


