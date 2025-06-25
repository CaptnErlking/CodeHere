#include<bits/stdc++.h>
using namespace std; 
const int MOD = 1e9 + 7;
 
// state : dp[i][j] meaning maximum pages till ith book with j amount
// transition : dp[i][j] = max(take, notTake)

/*
int getPages(int n, int x, vector<int> &prices, vector<int> &pages, vector<vector<int>> &dp) {
	if (n < 0 || x < 0) return 0; 
	if (dp[n][x] != -1) return dp[n][x]; 
 
	int notTake = getPages(n - 1, x, prices, pages, dp); 
	int take = (x < prices[n]) ? 0 : getPages(n - 1, x - prices[n], prices, pages, dp) + pages[n]; 
 
	dp[n][x] = max(take, notTake); 
	return dp[n][x]; 
}
 
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
   	vector<vector<int>> dp(n, vector<int> (x + 1, -1)); 
   	cout << getPages(n - 1, x, prices, pages, dp) << endl; 
}
*/

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