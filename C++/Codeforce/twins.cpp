#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
int main() {
    int n;  
    cin >> n; 
    int TotalMoney=0;
    vector<int> v(n);
    for (int i=0; i<n; i++){
        cin >> v[i];
        TotalMoney+=v[i];
    }
    sort(v.begin(), v.end());
    TotalMoney/=2;
    int MyMoney=0;
    int coins=0;  
    for (int i=n-1; i>=0; i--){
        MyMoney+=v[i];
        coins++;
        if (MyMoney>TotalMoney) break;
    }
    cout << coins;
}