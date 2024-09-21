#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main()
{
    cout << "Enter a number to check if it is prime: ";
    int n;
    cin >> n;
    for (int i=2;i<pow(n,0.5);i++)
    {
        if (n%i==0)
        {
            cout << "It is not prime :(";
            exit(0);
        }
    }
    cout << "It is a prime :)";
}