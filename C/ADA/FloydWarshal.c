#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void floydWarshall(int **graph, int vertices) {
    for (int k = 0; k < vertices; ++k) {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX) {
                    if (graph[i][j] > graph[i][k] + graph[k][j]) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int **graph = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int));
    }

    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (i == j) {
                graph[i][j] = 0;  
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dst weight):\n");
    for (int i = 0; i < edges; ++i) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight; 
    }

    floydWarshall(graph, vertices);

    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (graph[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", graph[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
