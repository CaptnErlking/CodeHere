#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number to get the all the Odd number in it: " ;
    cin >> n ;
    for (int i=1;i<=n;i+=2)
    {
        cout <<" "<<i<<" \n";
    }
    return 0;
}