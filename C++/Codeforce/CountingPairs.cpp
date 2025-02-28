#include<bits/stdc++.h>
using namespace std; 

int searchAtleast(vector<int> &a, int n, int atleast) {

}

int searchAtmost(vector<int> &a, int n, int atmost) {

}

int countPairs(vector<int> &a, int n, int x, int y, int total) {
    sort(a.begin(), a.end()); 
    int pairs = 0; 
    for (int i = 0; i < n; i++) {
        int atleast = total - y < 0 ? 0 : total - y; 
        int atmost = total - x; 
        pairs += searchAtleast(a, n, atleast); 
        pairs += searchAtmost(a, n, atmost); 

    }
}

int main () {
    int t, n, x, y; 
    cin >> t; 
    while (t--) {
        cin >> n >> x >> y;
        int total = 0; 
        vector<int> a(n); 
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
            total += a[i]; 
        }
        cout << countPairs(a, n, x, y, total) << endl; 
    }
}