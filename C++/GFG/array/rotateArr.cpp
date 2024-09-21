#include<iostream>
#include<utility>
using namespace std; 
void rotater(int arr[], int n, int r){
    for (int i=0 ; i<r/2 ; i++) swap(arr[i],arr[r-i-1]);
    for (int j=0 ; j<(n-r)/2 ; j++) swap (arr[r+j],arr[n-1-j]);
    for (int k=0 ; k<n/2 ; k++) swap (arr[k],arr[n-1-k]);
}
int main() {
    cout << "Enter the size of Array : " ; 
    int n ; 
    cin >> n ;
    cout << "Enter the elements of array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ; 
    cout << "How many elements do you want to rotate : " ; 
    int r ; 
    cin >> r ; 
    rotater(arr,n,r);
    cout << "Here in the rotated Array : " << endl ; 
    for (int i=0 ; i<n ; i++) cout << arr[i] << " " ; 
    return 0 ; 
}