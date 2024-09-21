#include<iostream>
#include<vector>
using namespace std;
void SieveOfErotosthenes(int n){
    vector<bool> v(n+1,true);
    for (int i=2 ; i<=n ; i++){
        if (v[i]) {
            cout << i << " " ;
            for (int j=i*i ; j<=n ; j+=i){
                v[j]=false;
            }
        }
    }
}
int main(){
    cout << "Gimme a number to get Primes : " ;
    int number; 
    cin >> number ; 
    SieveOfErotosthenes(number);
}