#include<iostream>
#include<climits>
using namespace std;
int reverser(int n)
{
    int rev=0;
    while (n!=0)
    {
        if ((rev>INT_MAX/10) || (rev<INT_MIN/10))
        {
            return 0;
        }
        rev=rev*10+n%10;
        n/=10;
    }
    cout << rev;
    return rev;
}
int main()
{
    int number;
    cout << "Enter a number to get its Reverse: " ;
    cin >> number ;
    number = reverser(number);
    cout << "The reverse of the number will be : " << number ;
    return 0;
}