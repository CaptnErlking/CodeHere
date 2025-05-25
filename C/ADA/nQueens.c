#include <stdio.h>
#include <math.h>

int a[30], count = 0;

int place(int pos) {
    for (int i = 1; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos))) {
            return 0;
        }
    }
    return 1;
}

void print_sol(int n) {
    count++;
    printf("\n\nSolution #%d:\n", count);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n, int row) {
    if (row > n) {
        print_sol(n);
        return;
    }

    for (int col = 1; col <= n; col++) {
        a[row] = col;

        if (place(row)) {
            queen(n, row + 1);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    queen(n, 1);
    printf("\nTotal solutions = %d\n", count);
    return 0;
}