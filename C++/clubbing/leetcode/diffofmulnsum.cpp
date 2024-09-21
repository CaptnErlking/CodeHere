#include<iostream>
using namespace std;
int main()
{
    int n,dig;
    cout << "Enter the number: ";
    cin >> n ;
    int sum=0,mul=1;
    while (n>0)
    {
        sum += n%10;
        mul *= n%10;
        n=n/10;
    }
    cout << "The difference of the product and sum of the digits is "<<mul-sum;
    return 0;
}