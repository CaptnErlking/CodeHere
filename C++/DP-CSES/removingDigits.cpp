#include<bits/stdc++.h>
using namespace std; 

// state : dp[i] meaning minimum number of steps to to reach 0 from i
// transition : dp[i] = 1 + min(dp[i - d[0]],..., dp[i - d[m]])
//                                   m = number of digits in i; 
/*
int removeDigits(int n, vector<int> &dp) {
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n]; 
    vector<int> digits; 
    int temp = n; 
    while (temp) {
        digits.push_back(temp % 10); 
        temp /= 10; 
    }
    int res = INT_MAX; 
    for (int i = 0; i < digits.size(); i++) {
        if (digits[i] == 0) continue; 
        int curr = removeDigits(n - digits[i], dp);
        res = min(res, curr + 1); 
    }
    dp[n] = res;
    return dp[n]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<int> dp(n + 1, -1); 
    cout << removeDigits(n, dp) << endl; 
}
*/

void fillDigits(int n, vector<int> &digits) {
    while (n) {
        digits.push_back(n % 10); 
        n /= 10; 
    }
}
int main() {
    int n; 
    cin >> n; 
    vector<int> dp(n + 1, 0);
    dp[0] = 0; 
    for (int i = 1; i <= n; i++) {
        vector<int> digits; 
        fillDigits(i, digits); 
        int res = INT_MAX;
        for (int digit : digits) {
            if (!digit) continue; 
            if (i - digit >= 0) {
                int curr = dp[i - digit]; 
                res = min(res, curr + 1); 
            }
        }
        dp[i] = res; 
    }
    cout << dp[n] << endl; 
}