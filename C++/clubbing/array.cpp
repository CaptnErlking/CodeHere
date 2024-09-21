#include<iostream>
using namespace std;
void inarr(int ray[],int x)
{
    for (int i=0;i<x;i++)
    {
        cout << "Enter the " << i << " element of Array : " ;
        cin >> ray[i] ;
    }
}
void outarr(int ray[],int x)
{
    cout << "The array is : " << endl ;
    for (int i=0;i<x;i++)
    {
        cout << ray[i] << " " ;
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array: " ;
    cin >> n ;
    int arr[n];
    inarr(arr,n);
    outarr(arr,n);
    int size;
    size = sizeof(arr)/sizeof(int);
    cout << endl << "THe size of Array actually is " << size ;
}