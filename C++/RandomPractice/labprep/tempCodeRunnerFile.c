#include <stdio.h>
 #define MAX 100
 #define INF 9999
 int main() {
    int cost[MAX][MAX], visited[MAX];
    int i, j, n, edges = 0, min, u = -1, v = -1, total = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix (use %d for no edge):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    for (i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;
    printf("Edges in MST:\n");
    while (edges < n - 1) {
        min = INF;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        printf("%d - %d : %d\n", u, v, min);
        total += min;
        edges++;
    }
    printf("Total cost of MST = %d\n", total);
    return 0;
 }
