#include<iostream>
using namespace std;
int pivot(int arr[], int n){
    int l=0, h=n-1;
    int m;
    while (l<h){
        m=l+(h-l)/2;
        if (arr[m]>arr[0]) l++;
        else h--;
    }
    return l;
}
int main(){
    int arr[] = {5,6,7,8,9,10,11,12,1,2,3,4}; 
    cout << "The pivot of this is Array is : " << pivot(arr,12) ;    
}