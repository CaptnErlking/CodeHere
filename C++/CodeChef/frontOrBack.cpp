#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int mod = 998244353;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<long long> m(n);
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0 && arr[i] < n) {
                m[arr[i]]++;
            }
        }
        long long r = 1;
        for (int j = 1; j <= n; j++) {
            int a = j - 1;
            int b = n - j;
            long long p;
            if (a == b) {
                p = m[a];
            } else {
                p = m[a] + m[b];
            }
            if (p == 0) {
                r = 0;
                break;
            }
            r = (r * p) % mod;
            if (a == b) {
                m[a]--;
            } else if (m[a] > 0) {
                m[a]--;
            } else {
                m[b]--;
            }
        }
        cout << r << endl;
    }
    return 0;
}
