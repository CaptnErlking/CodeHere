#include<iostream>
using namespace std; 

int theatre(int n, int m, int a) {
    int row, col; 
    if (n % a == 0) col = n / a;
    else col = (n / a) + 1; 
    if (m % a == 0) row = m / a;
    else row = (m / a) + 1;
    return row * col; 
}
int main() {
    int n, m, a; 
    cin >> n >> m >> a; 
    cout << theatre(n, m, a) ;
}