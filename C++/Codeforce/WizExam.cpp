#include <bits/stdc++.h>
using namespace std;

pair<long long int, long long int> wiz(vector<long long int> &v, long long int n) {
    long long int maxi = 0; 
    long long int ms = 0, me = 0; 
    for (long long int i = 0; i < n; i++) {
        long long int curr = 0; 
        for (long long int j = i; j < n; j++) {
            if (v[j] < v[i]) curr--; 
            if (v[j] > v[i]) curr++; 
            if (maxi > curr) {
                maxi = curr; 
                ms = i; 
                me = j; 
            }
        }
    }
    return {ms + 1, me + 1};
}

long long int main() {
    long long int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long int> v(n);
        for (long long int i = 0; i < n; i++) cin >> v[i];

        pair<long long int, long long int> x = wiz(v, n);
        cout << x.first << " " << x.second << endl;
    }
}
