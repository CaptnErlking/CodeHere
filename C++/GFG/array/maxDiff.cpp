#include<iostream>
using namespace std;
int maxDiff(int arr[], int n){
    int max_dif = arr[1]-arr[0] ; 
    int min_val = arr[0];
    for (int i=1 ; i<n ; i++){
        if (arr[i]-min_val > max_dif)
            max_dif = arr[i] - min_val; 
        if (arr[i] < min_val) 
            min_val = arr[i];
    }
    return max_dif; 
}
int main(){
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    int arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ; 
    int md = maxDiff(arr,n);
    cout << "The maximum difference is : " << md << endl ; 
}