#include<iostream>
#include<algorithm>
using namespace std; 
bool pairSumSorted(int arr[], int n, int key){
    sort(arr,arr+n);
    int low = 0; 
    int high = n-1; 
    while (low<=high){
        if (arr[low]+arr[high]==key) return true; 
        else if (arr[low]+arr[high]>key) high--; 
        else low++; 
    }
    return false; 
}
int main() {
    cout << "Enter the number of elements: " ; 
    int n; 
    cin >> n;
    int arr[n];  
    cout << "Enter the elements : " << endl ; 
    for (int i=0; i<n; i++) cin >> arr[i]; 
    cout << "Enter the Sum : " ; 
    int key; 
    cin >> key; 
    if (pairSumSorted(arr,n,key)) cout << "The pair is present :) " << endl ; 
    else cout << "The pair is not present :( " << endl ; 
}