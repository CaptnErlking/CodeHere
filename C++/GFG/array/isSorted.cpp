#include<iostream>
using namespace std;
bool isSorted(int arr[], int n){
    for (int i=0 ; i<n-1 ; i++) if (arr[i]>arr[i+1]) return false;
    return true;
}
int main(){
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ; 
    isSorted(arr,n) ? cout << "It is Sorted!" : cout << "It is not Sorted!" ;
}