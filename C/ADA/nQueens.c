#include <stdio.h>
#include <math.h>

int a[30], count = 0;  // Array to store queen positions (index = row, value = column)

// Function to check if placing a queen at 'pos' row is safe
int place(int pos) {
    for (int i = 1; i < pos; i++) {
        // Check if there's a queen in the same column or on the same diagonal
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos))) {
            return 0;  // Conflict found
        }
    }
    return 1;  // No conflict, it's safe
}

// Function to print a solution
void print_sol(int n) {
    count++;  // Increment the solution count
    printf("\n\nSolution #%d:\n", count);

    // Print the board
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i] == j)  // If queen is placed in column 'j' on row 'i'
                printf("Q\t");  // Print a queen
            else
                printf("*\t");  // Empty space
        }
        printf("\n");
    }
}

// Recursive backtracking function to place queens on the board
void queen(int n, int row) {
    if (row > n) {  // If all queens are placed (base case)
        print_sol(n);  // Print the solution
        return;  // Return to previous call (backtrack)
    }

    // Try placing a queen in each column of the current row
    for (int col = 1; col <= n; col++) {
        a[row] = col;  // Place queen in the current column

        if (place(row)) {  // Check if it's safe to place the queen
            queen(n, row + 1);  // Recursively place queens in the next row
        }

        // If placing queen at column 'col' doesn't lead to a solution, backtrack (try the next column)
        // No need to undo anything here because we are just assigning a new value to 'a[row]'
    }
}

// Main function to drive the N-Queens solution
int main() {
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d", &n);  // Read the size of the board (number of queens)

    // Start placing queens from the first row (row = 1)
    queen(n, 1);

    printf("\nTotal solutions = %d\n", count);  // Print the total number of solutions found
    return 0;
}
