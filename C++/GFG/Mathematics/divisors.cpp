#include<iostream>
#include<math.h>
using namespace std; 
void divisors(int n){
    int count = 0; 
    for (int i=1 ; i*i<n ; i++){
        if (n%i==0){
            cout << i << " " ;
            count++;
        }
    }
    for (int  i=pow(n,0.5); i>0 ; i--){
        if (n%i==0){
            cout << n/i << " " ;
            count++;
        }
    }
    cout << endl << "Number of Divisors : " << count ; 
}
int main() {
    cout << "Enter a number to get its Divisors: " ;
    int n;
    cin >> n ;
    divisors(n);

}