#include<iostream>
using namespace std; 
int power(int x,int n){
    if (n==0) return 1;
    int temp = power(x,n/2);
    temp*=temp;
    if (n%2==0) return temp;
    else return temp*x;
}
int bitPower(int x,int  n){
    int res=1; 
    while (n>0){
        if (n&1) res*=x;
        x*=x;
        n>>=1;
    }
    return res;
}
int main(){
    cout << "Enter a number : " ;
    int x; 
    cin >> x ; 
    cout << "It's power : " ;
    int n; 
    cin >> n; 
    cout << x << " to the power " << n << " is " << bitPower(x,n) ;
}