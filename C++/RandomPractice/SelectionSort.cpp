#include <iostream>
using namespace std;
void swapper(int *x, int *y);
int main() {
    int arr[1000];
    int n=0; 
    cout << "Enter the size of Array: " ;
    cin >> n; 
    for (int i=0; i<n ; i++){
        cout << ": " ;
        cin >> arr[i] ;
    }
    for (int i=0; i<n-1 ; i++){
        int smol=i; 
        for (int j=i+1; j<n ; j++){
            if (arr[j]<arr[smol]){
                smol=j;
            }
        }
        swap(arr[i],arr[smol]);
    }
    cout << "Here is the sorted array : " << endl ;
    for (int i=0; i<n ; i++){
        cout << arr[i] << " " ;
    }
}
void swapper(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}