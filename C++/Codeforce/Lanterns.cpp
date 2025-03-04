#include <bits/stdc++.h>
using namespace std;

double minR(vector<int>& x, int n, int l) {
    sort(x.begin(), x.end());  
    double max_gap = 0.0;
    for (int i = 1; i < n; i++) {
        max_gap = max(max_gap, (x[i] - x[i - 1]) / 2.0);
    }
    max_gap = max({max_gap, (double)x[0], (double)(l - x[n - 1])});
    return max_gap;
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << fixed << setprecision(10) << minR(x, n, l) << endl;
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

bool isFeasible(vector<int>& x, int n, double d, int l) {
    if (x[0] > d || (l - x[n - 1]) > d) return false;
    
    for (int i = 1; i < n; i++) {
        if ((x[i] - x[i - 1]) / 2.0 > d) {
            return false;
        }
    }
    return true;
}

double minR(vector<int>& x, int n, int l) {
    sort(x.begin(), x.end());
    
    double low = 0, high = l, mid;
    double epsilon = 1e-9; 
    
    while (high - low > epsilon) {
        mid = (low + high) / 2.0;
        if (isFeasible(x, n, mid, l)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return high;
}

int main() {
    int n, l;
    cin >> n >> l;
    
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    
    cout << fixed << setprecision(10) << minR(x, n, l) << endl;
    return 0;
}
*/
