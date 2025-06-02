#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int a[30], count = 0; 

bool place(int row) {
    for (int i = 1; i < row; i++) {
        if (a[i] == a[row] || abs(a[i] - a[row]) == abs(i - row)) return false; 
    }
    return true; 
}

void sol(int n) {
    count++; 
    printf("Sol %d\n", count); 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j) printf("Q\t"); 
            else printf(".\t"); 
        }
        printf("\n"); 
    } 
    printf("\n"); 
}

void q(int n, int row) {
    if (row > n) {
        sol(n);
        return;
    }
    for (int col = 1; col <= n; col++) {
        a[row] = col; 
        if (place(row)) {
            q(n, row + 1); 
        }
    }
}

int main() {
    int n; 
    printf("Enter dimension : "); 
    scanf("%d", &n); 
    q(n, 1);
}