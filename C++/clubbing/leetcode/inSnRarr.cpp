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
int bininsnr(int arr[], int n, int t){
    int l=0, h=n-1;
    int m;
    if (t>arr[0]) h=pivot(arr,n);
    else l=pivot(arr,n);
    while (l<=h){
        if (arr[m]==t) break;
        else if (t<arr[m]) h=m-1;
        else l=m+1;
    }
    return m;
}
int main(){
    int arr[] = {5,6,7,8,9,10,11,12,1,2,3,4}; 
    int target = 10;  
    cout << "Your target is present at index: " << bininsnr(arr,12,target) ;
}