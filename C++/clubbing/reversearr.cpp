#include<iostream>
#include<algorithm>
using namespace std;
void reverser ( int* arr, int n)
{
    for (int i=0 ; i<n/2 ; i++)
    {
        swap(arr[i],arr[n-i-1]);
    }
}
int main() 
{
    int arr[1000],n;
    cout << "Enter the number of Elements: " ;
    cin >> n ;
    for (int i=0 ; i<n ; i++)
    {
        cout << "Enter Element " << i+1 << ": " ;
        cin >> arr[i] ;
    }
    reverser(arr,n);
    cout << "The Reversed array will be : " << endl ; 
    for (int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " " ;
    }
}