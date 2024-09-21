#include<iostream>
using namespace std;
int CountSetBits(int n){
    /*
    int count=0 ;
    while (n>0){
        if (n&1) count++;
        n>>=1;
    }
    return count;
    */
   
   int count = 0 ; 
   while (n>0){
        n&=(n-1);
        count++;
   }
   return count;
}
int main(){
    cout << "Enter a number : " ;
    int n ;
    cin >> n ;
    cout << "The number of SetBits in "<< 
    "the Binary representation of " 
    << n << " is " << CountSetBits(n) << endl ;
    if (CountSetBits(n)==1) cout << "Also this is a Power of Two " ;
}