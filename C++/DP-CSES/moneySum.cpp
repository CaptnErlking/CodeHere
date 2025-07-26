#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i] meaning the number of possible sums till ith coin
// transition : dp[i] = x + dp[i - 1] where x is the number of 
//              new entries in the set
//              We will add coin[i] to all the previous set members 
//              and increment x if the new sum is not in set

int solve(int i, vector<int> &c, set<int> &s, vector<int> &dp) {
    if (i < 0) return 0; 
    if (dp[i] != -1) return dp[i]; 
    vector<int> temp; 
    int x = 0; 
    dp[i] = solve(i - 1, c, s, dp); 
    for (auto it : s) {
        int take = it + c[i]; 
        if (!s.count(take)){
            temp.push_back(take); 
            x++; 
        }       
    }
    dp[i] += x; 
    for (auto it : temp) s.insert(it); 
    return dp[i]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<int> c(n); 
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<int> dp(n + 1, -1); 
    set<int> s; 
    s.insert(0); 
    cout << solve(n - 1, c, s, dp) << endl;
    for (auto it : s) if (it != 0) cout << it << " "; 
    cout << endl; 
}