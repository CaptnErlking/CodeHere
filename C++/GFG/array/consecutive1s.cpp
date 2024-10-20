#include<iostream>
using namespace std;
int most1s(bool arr[], int n){
    int mx=0;
    bool flag = false;
    int tmpmx=0;
    for (int i=0; i<n ; i++){
        tmpmx=0;
        if (arr[i]) flag=true;
        if (flag==true) {
            while(arr[i] && i<n) {
                tmpmx++;
                i++;
            }
        }
        flag=false;
        if (tmpmx>mx) mx = tmpmx;
    }
    return mx; 
}
int main () {
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    bool arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    cout << "The most number of consecutive 1's is : " << most1s(arr,n);
}