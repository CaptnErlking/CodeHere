#include<stdio.h>

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int part(int arr[], int l, int r) {
    int p = arr[l]; 
    int i = l; 
    int j = r; 
    while (i < j) {
        while (arr[i] <= p && i < r) i++; 
        while (arr[j] > p && j > l) j--; 
        if (i < j) {
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[l], &arr[j]); 
    return j;   
}

void qs(int arr[], int l, int r) {
    if (l < r) {
        int p = part(arr, l, r); 
        qs(arr, l , p - 1); 
        qs(arr, p + 1, r); 
    }
}

int main() {
    int n; 
    printf("Enter number of elements : "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter the array : ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    qs(arr, 0, n - 1); 
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
    printf("\n"); 
}