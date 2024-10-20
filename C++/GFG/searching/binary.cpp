#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
void binarysearch(vector<int> v, int n, int key){
    int low=0; 
    int high=n-1;
    while (low<=high){
        int mid = (low+high)/2;
        if (v[mid]==key){
            cout << "Element was found at " << mid << endl ;
            return;  
        }
        else if (v[mid]>key){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    cout << "Element was not found :(" << endl ; 
    return ; 
}
int main() {
    cout << "Enter the size of array : " ; 
    int n ; 
    cin >> n;
    vector<int> v;
    cout << "Enter the elements : " << endl;
    for (int i=0; i<n ; i++){
        int temp;
        cin >> temp;
        v.push_back(temp) ;
    } 
    sort(v.begin(), v.end());
    int key;
    cout << "Enter the key that you want to find : " ;
    cin >> key; 
    binarysearch(v,n,key);
    return 0; 
}