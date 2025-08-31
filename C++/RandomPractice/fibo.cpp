#include<bits/stdc++.h>
using namespace std; 

// state : dp[i] meaning fibonacci of ith number
// transition : dp[i] = f(i - 1) + f (i - 2)

int fibo(int n, vector<int> dp) {
    if (n == 1 || n == 2) return 1; 
    if (dp[n] != -1) return dp[n]; 
    dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp); 
    return dp[n]; 
}

int main() {
    int n; 
    cin >> n; 
    vector<int> dp(n + 1, -1); 
    cout << fibo(n, dp) << endl; 
}