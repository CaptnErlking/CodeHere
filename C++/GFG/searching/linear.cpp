#include<iostream>
using namespace std; 
void linear (int arr[], int n, int key){
    for (int i=0; i<n; i++)
        if (arr[i]==key){ 
            cout << "Key was found at " << i << endl ; 
            return ; 
        }
    cout << "Key was not found  :(" << endl ; 
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
    linear(arr,n,key);
    return 0;
}