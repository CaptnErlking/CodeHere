#include<stdio.h>
void findLargestInRow(int (*arr)[20], int *r, int *c) {
    for (int i=0; i < *r; i++) {
        int max = arr[i][0]; 
        for (int j=1; j < *c; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j]; 
            }
        }
        printf("Largest of %d row  is : %d\n", i+1, max); 
    }   
}
int main() {
    printf("Ente the size of row and coloumn : \n"); 
    int r, c; 
    scanf("%d%d", &r, &c); 
    int *row = &r; 
    int *col = &c; 
    int arr[20][20]; 
    printf("Enter the elements of the Matrix : \n"); 
    for (int i=0; i < *row; i++) {
        for (int j=0; j < *col; j++) {
            scanf("%d", &arr[i][j]); 
        }
    }
    findLargestInRow(arr, row, col); 
}