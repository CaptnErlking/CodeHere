#include <bits/stdc++.h>
using namespace std;

string prep(vector<int> &qlist, set<int> &knows, int n, int m) {
    string ans = "";
    for (int i = 0; i < m; i++) {
        int missing = qlist[i];
        bool canPass = true;

        for (int q = 1; q <= n; q++) {
            if (q != missing && knows.find(q) == knows.end()) {
                canPass = false;
                break;
            }
        }

        ans += (canPass ? '1' : '0');
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> qlist(m);
        for (int i = 0; i < m; i++) {
            cin >> qlist[i];
        }

        set<int> knows;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            knows.insert(x);
        }

        cout << prep(qlist, knows, n, m) << '\n';
    }
}
