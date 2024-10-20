#include<iostream>
using namespace std; 
int EvenOdd(int arr[], int n){
    int res=1;
    for (int i=0; i<n; i++){
        int curr=1;
        for (int j=i+1; j<n; j++){    
            if((arr[j]%2==0 && arr[j-1]%2 !=0)||(arr[j]%2!=0 && arr[j-1]%2 ==0)){
                curr++;
            }
            else {
                break;
            }
        }
        res=max(res,curr);
    }
    return res;
}
int main () {
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    int x = EvenOdd(arr,n);
    cout << "The Length of the longest subarray is: " << x << endl ; 
}