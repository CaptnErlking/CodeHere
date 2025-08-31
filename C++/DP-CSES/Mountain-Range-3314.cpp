#include<bits/stdc++.h>
using namespace std; 
const int mod = 1e9 + 7; 

// wrong answer, ignore please

int main() {
    int n; 
    cin >> n; 
    vector<int> arr(n); 
    int maxi = -1; 
    for (int i = 0; i < n; i++) { 
        cin >> arr[i]; 
        maxi = max(arr[i], maxi);
    }
    vector<int> highest; 
    for (int i = 0; i < n; i++) if (arr[i] == maxi) highest.push_back(i); 
    int m = highest.size(); 
    int ans = highest[0]; 
    for (int i = 1; i < m; i++) {
        ans = max(highest[i] - highest[i - 1] - 1, ans); 
    }
    ans = max(n - highest[m - 1] - 1, ans); 
    cout << ans << endl; 
}