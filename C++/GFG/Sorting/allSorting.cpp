#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<vector<int>> steps;

void recordStep(int arr[], int n) {
    vector<int> temp(arr, arr + n);
    steps.push_back(temp);
}

void exportStepsToFile(const string& filename) {
    ofstream outFile(filename);
    outFile << "[";
    for (size_t i = 0; i < steps.size(); i++) {
        outFile << "[";
        for (size_t j = 0; j < steps[i].size(); j++) {
            outFile << steps[i][j];
            if (j != steps[i].size() - 1) outFile << ",";
        }
        outFile << "]";
        if (i != steps.size() - 1) outFile << ",";
    }
    outFile << "]";
    outFile.close();
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            recordStep(arr, n);
        }
    }
}

// Insertion Sort
void iSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        recordStep(arr, n);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }
        swap(arr[i], arr[min_ind]);
        recordStep(arr, n);
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int h) {
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
        recordStep(arr, h + 1);
    }
    while (i < n1) {
        arr[k++] = left[i++];
        recordStep(arr, h + 1);
    }
    while (j < n2) {
        arr[k++] = right[j++];
        recordStep(arr, h + 1);
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(arr[i], arr[j]);
        recordStep(arr, h + 1);
    }
}

void qSort(int arr[], int l, int h) {
    if (l < h) {
        int p = partition(arr, l, h);
        qSort(arr, l, p);
        qSort(arr, p + 1, h);
    }
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
        recordStep(arr, n);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        recordStep(arr, n);
    }
}

// Main Function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Bubble Sort
    steps.clear();
    bubbleSort(arr, n);
    exportStepsToFile("bubbleSort.json");

    // Insertion Sort
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    steps.clear();
    iSort(arr1, n);
    exportStepsToFile("insertionSort.json");

    // Selection Sort
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    steps.clear();
    selectionSort(arr2, n);
    exportStepsToFile("selectionSort.json");

    // Merge Sort
    int arr3[] = {64, 34, 25, 12, 22, 11, 90};
    steps.clear();
    mergeSort(arr3, 0, n - 1);
    exportStepsToFile("mergeSort.json");

    // Quick Sort
    int arr4[] = {64, 34, 25, 12, 22, 11, 90};
    steps.clear();
    qSort(arr4, 0, n - 1);
    exportStepsToFile("quickSort.json");

    // Heap Sort
    int arr5[] = {64, 34, 25, 12, 22, 11, 90};
    steps.clear();
    heapSort(arr5, n);
    exportStepsToFile("heapSort.json");

    return 0;
}
