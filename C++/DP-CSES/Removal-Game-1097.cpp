#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

// state : dp[i][j] meaning the maximum score the current player can get 
//         from the subarray arr[i...j].

// transition : 
// To calculate dp[i][j], the current player chooses the move that maximizes their score.

// Let score_if_taking_left be the player's total score if they take arr[i].
//    - The opponent plays on arr[i+1...j] and will score dp[i+1][j].
//    - The current player gets the rest from that subgame, which is (sum(i+1, j) - dp[i+1][j]).
//    - score_if_taking_left = arr[i] + sum(i+1, j) - dp[i+1][j]

// Let score_if_taking_right be the player's total score if they take arr[j].
//    - The opponent plays on arr[i...j-1] and will score dp[i][j-1].
//    - The current player gets the rest from that subgame, which is (sum(i, j-1) - dp[i][j-1]).
//    - score_if_taking_right = arr[j] + sum(i, j-1) - dp[i][j-1]

// The final value is the maximum of the two choices.
// dp[i][j] = max(score_if_taking_left, score_if_taking_right)

long long get_sum(int l, int r, const vector<long long>& prefix_sum) {
    if (l > r) return 0LL;
    return prefix_sum[r + 1] - prefix_sum[l];
}

/*
long long solve(int l, int r, const vector<long long>& arr, const vector<long long>& prefix_sum, vector<vector<long long>>& dp) {
    if (l > r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    long long pick_left = arr[l] + (get_sum(l + 1, r, prefix_sum) - solve(l + 1, r, arr, prefix_sum, dp));
    long long pick_right = arr[r] + (get_sum(l, r - 1, prefix_sum) - solve(l, r - 1, arr, prefix_sum, dp));
    return dp[l][r] = max(pick_left, pick_right);
}
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> prefix_sum(n + 1, 0);
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (i == j) {
                dp[i][j] = arr[i];
                continue;
            }
            long long pick_left = arr[i] + (get_sum(i + 1, j, prefix_sum) - dp[i + 1][j]);
            long long pick_right = arr[j] + (get_sum(i, j - 1, prefix_sum) - dp[i][j - 1]);
            dp[i][j] = max(pick_left, pick_right);
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}

