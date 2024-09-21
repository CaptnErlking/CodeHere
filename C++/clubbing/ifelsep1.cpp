#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout << "Enter the length of sides of triangle: ";
    cin >> a >> b >> c;
    if (a+b>c && b+c>a && c+a>b)
    {
        cout << "It is a valid Triangle";
    }
    else 
    {
        cout << "It is not a valid triangle";
    }
    return 0;
}