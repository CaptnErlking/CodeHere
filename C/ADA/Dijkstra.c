#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int vertex;
    int weight;
} Node;

void dijkstra(int start, int vertices, Node *graph[], int distances[]) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        distances[i] = INT_MAX;
        visited[i] = 0;
    }
    distances[start] = 0;

    for (int i = 0; i < vertices; i++) {
        int minDistance = INT_MAX, currentVertex = -1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && distances[v] < minDistance) {
                minDistance = distances[v];
                currentVertex = v;
            }
        }

        if (currentVertex == -1) break;

        visited[currentVertex] = 1;
        Node *neighbor = graph[currentVertex];
        while (neighbor != NULL) {
            int nextVertex = neighbor->vertex;
            int weight = neighbor->weight;

            if (!visited[nextVertex] && distances[currentVertex] + weight < distances[nextVertex]) {
                distances[nextVertex] = distances[currentVertex] + weight;
            }
            neighbor = neighbor->next;
        }
    }
}

void addEdge(Node *graph[], int u, int v, int weight) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = weight;
    newNode->next = graph[u];
    graph[u] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = u;
    newNode->weight = weight;
    newNode->next = graph[v];
    graph[v] = newNode;
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    Node *graph[vertices];
    for (int i = 0; i < vertices; i++) {
        graph[i] = NULL;
    }

    printf("Enter edges (src dst weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(graph, u, v, weight);
    }

    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    int distances[vertices];
    dijkstra(start, vertices, graph, distances);

    printf("Shortest distances from vertex %d:\n", start);
    for (int i = 0; i < vertices; i++) {
        if (distances[i] == INT_MAX) {
            printf("Vertex %d: -1\n", i);
        } else {
            printf("Vertex %d: %d\n", i, distances[i]);
        }
    }

    return 0;
}
