#include<iostream>
using namespace std;
int main(){
    cout << "Here I am trying to figure out 2d arrays..." << endl ;
    int row = 3, col = 5;
    int arr[row][col];
    cout << "Alr give input: "     ;

    
    for (int i=0 ; i<row ; i++){
        int sum = 0;
        for (int j=0 ; j<col ; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0 ; i<row ; i++){
        int sum = 0;
        for (int j=0 ; j<col ; j++){
            sum+=arr[i][j];
        }
        cout << "Sum of element of row " << i << ": " << sum << endl ;
    }
}