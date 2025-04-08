#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long long int *a, long long int *b) {
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int partition(long long int arr[], long long int low, long long int high) {
    long long int pivot = arr[low];
    long long int i = low;
    long long int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(long long int arr[], long long int low, long long int high) {
    if (low < high) {
        long long int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
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

    printf("Original Array:\n");
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array:\n");
    for (long long int i = 0; i < n; i++) {
        printf("%lld ", arr[i]);
    }
    printf("\n");

    printf("Time taken for the sorting is: %lf seconds\n", time_taken);

    free(arr);
    return 0;
}
