#include<iostream>
using namespace std;
void freqPrinter(int arr[], int n){
    for (int i=0; i<n-1 ; i++){
        cout << arr[i] << " " ;
        int count = 1;
        while(arr[i]==arr[i+1]) {
            count++;
            i++;
        }
        cout << count << endl; 
    }
    if (n==1 || (arr[n-1]!=arr[n-2])) cout << arr[n-1] << " 1" << endl ;
}
int main () {
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    freqPrinter(arr,n);
}