#include<bits/stdc++.h>
using namespace std; 

int fibos(int arr[5]) {
    int ans = 1; 
    arr[2] = arr[0] + arr[1]; 
    if (arr[3] == arr[1] + arr[2]) ans++; 
    if (arr[4] == arr[2] + arr[3]) ans++; 
    int temp = 1; 
    arr[2] = arr[3] - arr[1]; 
    if (arr[4] == arr[2] + arr[3]) temp++; 
    if (arr[2] == arr[0] + arr[1]) temp++; 
    ans = max(temp, ans); 
    temp = 1; 
    arr[2] = arr[4] - arr[3]; 
    if (arr[2] == arr[0] + arr[1]) temp++; 
    if (arr[3] == arr[1] + arr[2]) temp++; 
    ans = max(temp, ans); 
    return ans; 
}

int main() {
    int t; 
    cin >> t; 
    while (t--) {
        int arr[5]; 
        cin >> arr[0] >> arr[1] >> arr[3] >> arr[4]; 
        cout << fibos(arr) << endl; 
    }
}