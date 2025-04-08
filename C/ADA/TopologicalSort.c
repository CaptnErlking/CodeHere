#include <stdio.h>
#include <stdlib.h>

void topologicalSort(int V, int adj[V][V]) {
    int indegree[V];
    for (int i = 0; i < V; i++) {
        indegree[i] = 0;
    }


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    int queue[V], front = 0, rear = 0;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int visitedCount = 0;
    int topOrder[V];

    while (front < rear) {
        int current = queue[front++];
        topOrder[visitedCount++] = current;

        for (int i = 0; i < V; i++) {
            if (adj[current][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    if (visitedCount != V) {
        printf("The graph contains a cycle. Topological sort is not possible.\n");
        return;
    }

    printf("Topological Order: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", topOrder[i]);
    }
    printf("\n");
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int adj[V][V];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &E);
    printf("Enter the edges (src dst):\n");
    for (int i = 0; i < E; i++) {
        int src, dst;
        scanf("%d %d", &src, &dst);
        adj[src][dst] = 1;
    }

    topologicalSort(V, adj);

    return 0;
}
