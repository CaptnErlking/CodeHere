#include<iostream>
using namespace std; 
int countdigits(int n){
    int count = 0 ; 
    while (n!=0){
        count++;
        n/=10;
    }
    return count; 
}
bool isPallindrome(int n){
    int temp = n;
    int revNum = 0; 
    while (n!=0){
        revNum = revNum*10 + n % 10 ;
        n/=10; 
    }
    return (revNum==temp);
}
int factorial(int n){
    if(n==0 || n==1) return 1;
    else return (n*factorial(n-1));
}
int trailingZeroes(int n){
    int c5 = 0;
    for (int i=5; i<=n ; i*=5)  c5 += n/i;
    return c5;
}
int gcd(int a, int b){
    if (b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    cout << "Enter a whole number : " ; 
    int number;
    cin >> number ;
    cout << "Here is the number of digits in it : " << countdigits(number) << endl ;
    cout << "This is a number is a Pallindrome : " << isPallindrome(number) << endl ; 
    cout << endl << "Enter a positive number to get it's Factorial : " ; 
    int fnum;
    cin >> fnum ; 
    cout << "The factorial of this number is : " << factorial(fnum) << endl ; 
    cout << "Enter a number to get the trailing zeroes in its factorial : " ;
    int tznum;
    cin >> tznum; 
    cout << "The number of trailing zeroes are : " << trailingZeroes(tznum) << endl ;
    cout << "Enter 2 numbers to get theie GCD : " << endl ;
    int gc1,gc2;
    cin >> gc1 ;
    cin >> gc2 ; 
    cout << "The GCD of these two nunbers is : " << gcd(gc1,gc2) ;  
}