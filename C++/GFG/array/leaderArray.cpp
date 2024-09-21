#include<iostream>
#include<climits>
using namespace std; 
void leader(int arr[], int n){
    int max = INT_MIN ; 
    for (int i=n-1 ; i>=0 ; i--)    if (arr[i]>max) cout << 
}
int main () {
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ; 
    cout << "The Leaders in this Array are : " << endl ; 
    leader(arr,n);
}