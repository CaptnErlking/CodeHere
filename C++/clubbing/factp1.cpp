#include<iostream>
using namespace std;
int main()
{
    cout << "Enter a number to get its Factorial: ";
    int fact=1,n;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    cout << "The Factorial of the Number is " << fact;
    return 0;
}