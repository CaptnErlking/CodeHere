#include<bits/stdc++.h>
using namespace std; 

int strat(int arr[], int brr[], int n) {
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        int first = arr[i]; 
        int second = (i == n - 1) ? 0 : brr[i + 1]; 
        ans += (first > second) ? (first - second) : 0; 
    }
    return ans; 
}

int main() {
    int t, n;   
    cin >> t; 
    while (t--) {
        cin >> n; 
        int arr[n]; 
        int brr[n]; 
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; 
        }
        for (int i = 0; i < n; i++) {
            cin >> brr[i]; 
        }
        cout << strat(arr, brr, n) << endl; 
    }
}