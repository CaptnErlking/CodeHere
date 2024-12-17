#include <stdio.h>
void findElement (int * arr, int *n, int * x) {
    int *ptr = arr; 
    for (int i=0; i<*n; i++) {
        if (*ptr == *x) {
            printf("The element was found at %d index\n", i); 
            return; 
        }
        ptr++; 
    }
    printf("The element was not found :(\n"); 
}
int main() {
    printf("Enter the number of elements : "); 
    int n; 
    scanf("%d", &n); 
    int arr[n];
    printf("Enter the elements of Array : \n");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]); 
    }
    printf("Enter the elements that you want to find : "); 
    int x; 
    scanf("%d", &x); 
    findElement(arr, &n, &x);
}