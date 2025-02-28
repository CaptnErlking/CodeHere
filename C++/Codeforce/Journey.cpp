#include <bits/stdc++.h>
using namespace std;

long long int journey(long long int n, long long int a, long long int b, long long int c) {
    long long int cycle = a + b + c;
    long long int fullCycles = n / cycle;
    long long int currSum = fullCycles * cycle;
    long long int days = fullCycles * 3;

    if (currSum >= n) return days;

    if (currSum + a >= n) return days + 1;
    if (currSum + a + b >= n) return days + 2;
    return days + 3;
}

int main() {
    long long int t, n, a, b, c;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c;
        cout << journey(n, a, b, c) << endl;
    }
}
