#include<iostream>
using namespace std;
void reverse(int arr[], int n){
    for (int i=0 ; i<n/2 ; i++){
        arr[i]=arr[i]^arr[n-1-i];
        arr[n-i-1]=arr[i]^arr[n-1-i];
        arr[i]=arr[i]^arr[n-1-i];
    }
}
int main(){
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ; 
    reverse(arr,n);
    cout << "The reverse of that Array is : " << endl ;
    for (int i=0 ; i<n ; i++) cout << arr[i] << " " ;
}