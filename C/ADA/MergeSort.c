#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(long long int arr[], long long int left, long long int mid, long long int right) {
    long long int n1 = mid - left + 1;
    long long int n2 = right - mid;
    long long int *L = (long long int *)malloc(n1 * sizeof(long long int));
    long long int *R = (long long int *)malloc(n2 * sizeof(long long int));

    for (long long int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (long long int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    long long int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(long long int arr[], long long int left, long long int right) {
    if (left < right) {
        long long int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    clock_t start, end;
    double time_taken;

    printf("Enter the size of the array: ");
    long long int n;
    scanf("%lld", &n);

    long long int *arr = (long long int *)malloc(n * sizeof(long long int));
    for (long long int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    /*
    printf("Original Array:\n");
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");
    */
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    /*
    printf("Sorted Array:\n");
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
        */
    printf("\n");

    printf("Time taken for the sorting is: %lf seconds\n", time_taken);

    free(arr);
    return 0;
}
