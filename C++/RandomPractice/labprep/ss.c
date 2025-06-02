#include<stdio.h>

void ss(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                arr[i] = arr[i] ^ arr[j]; 
                arr[j] = arr[i] ^ arr[j]; 
                arr[i] = arr[i] ^ arr[j]; 
            }
        }
    }
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
    printf("\n");
}

int main () {
    int n; 
    printf("Enter the number of elements : "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter the array:\n"); 
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    ss(arr, n); 
}