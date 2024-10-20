#include<iostream>
using namespace std; 
void recursiveBinary(int arr[], int n, int key, int low, int high, int mid){
    if (low>high) {
        cout << "Element was not found " << endl ; 
        return ; 
    }
    if (arr[mid]==key){
        cout << "Element was found :)" << endl ; 
        return ; 
    }
    else if (arr[mid]<key){
        recursiveBinary(arr,n,key,mid+1,high,(low+high)/2);
    }
    else {
        recursiveBinary(arr,n,key,low,mid-1,(low+high)/2);
    }
}
int main() {
    cout << "Enter the size of array : " ; 
    int n ; 
    cin >> n;
    int arr[n];
    cout << "Enter the elements : " << endl;
    for (int i=0; i<n ; i++)
        cin >> arr[i] ; 
    int key;
    cout << "Enter the key that you want to find : " ;
    cin >> key; 
    int low=0,high=n-1;
    int mid=(low+high)/2;
    recursiveBinary(arr,n,key,low,high,mid);
}