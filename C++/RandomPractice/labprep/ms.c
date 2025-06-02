#include<stdio.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int left[n1]; 
    int right[n2]; 
    for (int i = 0; i < n1; i++) {
        left[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            arr[k] = left[i]; 
            i++; 
        } else {
            arr[k] = right[j]; 
            j++; 
        }
        k++; 
    }
    while (i < n1) {
        arr[k] = left[i]; 
        i++; k++; 
    }
    while (j < n2) {
        arr[k] = right[j]; 
        j++; k++; 
    }
}

void ms(int l, int r, int arr[]) {
    if (l < r) {
        int m = (l + r) / 2;
        ms(l, m, arr); 
        ms(m + 1, r, arr); 
        merge(arr, l, m, r); 
    }
}

int main() {
    int n; 
    printf("Enter number of elements : "); 
    scanf("%d", &n); 
    int arr[n]; 
    printf("Enter the array : ");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]); 
    ms(0, n - 1, arr); 
    for (int i = 0; i < n; i++) printf("%d ", arr[i]); 
    printf("\n"); 
}