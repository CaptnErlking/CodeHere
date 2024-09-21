#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cout << "Enter n: " ; 
    cin >> n ; 
    if (n<=1) {
        cout << "This is neither prime nor composite :(" ;
        return 0;
    }
    for (int i=2 ; i<=pow(n,0.5); i++){
        if (n%i==0){
            cout << "This is not a prime number " ; 
            return 0;
        }
    }
    cout << "This is a prime number" ;
}