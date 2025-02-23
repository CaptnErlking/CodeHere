#include<iostream>
using namespace std; 

long long int theatre(long long int n,long long int m,long long int a) {
    long long int row, col; 
    if (n % a == 0) col = n / a;
    else col = (n / a) + 1; 
    if (m % a == 0) row = m / a;
    else row = (m / a) + 1;
    return row * col; 
}
int main() {
    long long int n, m, a; 
    cin >> n >> m >> a; 
    cout << theatre(n, m, a) ;
}