#include<iostream>
#include<utility>
using namespace std;
int dupRem(int arr[], int n){
    int realIndex = 0 ;
    for (int i=1 ; i<n ; i++) {
        if (arr[realIndex]!=arr[i]){
            swap(arr[++realIndex],arr[i++]);
        }
    }
    int i=0; 
    while (arr[i]<arr[i+1]) i++;
    return i+1;
}
int main(){
    cout << "Enter the size of the Array: " ; 
    int n ; 
    cin >> n ;
    cout << "Enter a Sorted Array with duplicates: " << endl ;
    int arr[n] ;
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    int newsize = dupRem(arr,n);
    cout << "Same Array without duplicates is : " << endl ;
    for (int i=0 ; i<newsize ; i++) cout << arr[i] << " " ; 
}