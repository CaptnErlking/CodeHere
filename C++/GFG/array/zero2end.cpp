#include<iostream>
#include<utility>
using namespace std; 
void zero2end(int arr[], int n){
    int zeroInd = 0 ;
    bool flag = false ; 
    for (int i=0 ; i<n-1 ; i++) {
        if (arr[i]==0) {
            if (flag == false){
                zeroInd = i ;
                flag = true ; 
            } 
            while (arr[i]==0 && i<n) i++ ;  
            swap(arr[zeroInd],arr[i]);
            i--; 
            zeroInd++;
        }
    }
}
int main() {
    cout << "Enter the number of Elements : " ;
    int n ; 
    cin >> n ;
    cout << "Enter the elements : " << endl ; 
    int arr[n] ; 
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    zero2end(arr,n);
    cout << "I moved all the zeroes to the end :) " << endl ; 
    for (int i=0 ; i<n ; i++) cout << arr[i] << " " ;
}