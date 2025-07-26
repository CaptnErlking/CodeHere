#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7; 

// state : dp[i][j] meaning length of the LCS till ith on A and jth on B strings
// transition : if A[i] == B[j] -> dp[i][j] = dp[i + 1][j + 1]
//              else either we take A[i] or we take B[j]
//              take from A -> dp[i + 1][j]
//              take from B -> dp[i][j + 1]

int solve(int i, int j, int n, int m,vector<int> &a, vector<int> &b, 
          vector<vector<int>> &dp) {
    if (i == n || j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (a[i] == b[j]) {
        return dp[i][j] = 1 + solve(i + 1, j + 1, n, m, a, b, dp);
    } else {
        return dp[i][j] = max(
            solve(i + 1, j, n, m, a, b, dp),
            solve(i, j + 1, n, m, a, b, dp)
        );
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int j = 0; j < m; j++) cin >> b[j];
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << solve(0, 0, n, m, a, b, dp) << endl;
    vector<int> lcs;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            lcs.push_back(a[i]);
            i++; 
            j++;
        }
        else if (dp[i+1][j] >= dp[i][j+1]) i++;
        else j++;
    }
    for (int x : lcs) 
        cout << x << " ";
    cout << "\n";
    return 0;
}