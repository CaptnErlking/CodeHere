#include<iostream>
using namespace std;
void minConsFlip(bool arr[], int n){
    int start=0, end=0; 
    bool flipme;
    for (int i=1; i<n ; i++) if (arr[i]!=arr[i-1]) flipme=arr[i];
    for (int i=0; i<n ; i++){
        bool flag = false;
        if (arr[i]==flipme) start=i;
        while (arr[i]==flipme && i<n){ 
            i++;
            flag = true;
        }
        end = i;
        if (flag && start!=end) cout << "Flip from " << start << " to " << end << endl ;

    }
}
int main () {
    cout << "Enter the size of Array: " ; 
    int n ; 
    cin >> n ; 
    cout << "Enter the elements of Array : " << endl ; 
    bool arr[n];
    for (int i=0 ; i<n ; i++) cin >> arr[i] ;
    cout << "The Minmum Consecutive flips are : " << endl ;
    minConsFlip(arr,n);
}