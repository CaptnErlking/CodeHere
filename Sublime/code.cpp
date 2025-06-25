#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout); 
#endif

	int n, x; 
    cin >> n >> x; 
    vector<int> prices(n); 
    vector<int> pages(n); 
    for (int i = 0; i < n; i++) cin >> prices[i]; 
    for (int i = 0; i < n; i++) cin >> pages[i]; 
   	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= prices[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << endl;
}