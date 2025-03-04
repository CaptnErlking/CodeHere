#include<bits/stdc++.h>
using namespace std; 

int cheapTravel(int n, int m, int a, int b) {
    if (m * a <= b) {
        return n * a; 
    }
    int cost1 = (n / m) * b; 
    int cost2 = 0; 
    int remaining = n % m; 
    if (remaining * a < b) cost2 = a * remaining; 
    else cost2 = b; 
    return cost1 + cost2;  
}

int main() {
    int n, m, a, b; 
    cin >> n >> m >> a >> b; 
    cout << cheapTravel(n, m, a, b) << endl; 
}