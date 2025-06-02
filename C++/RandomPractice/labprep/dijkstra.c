#include<stdio.h>
#define inf 999
#include<limits.h>
#define max 100
int adj[max][max]; 
int n; 

int findMin(int dist[], int vis[]) {
    int min = inf; int mi = -1; 
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dist[i] < min) {
            min = dist[i]; 
            mi = i; 
        }
    }
    return mi; 
}

void dijkstra(int src, int dist[]) {
    int vis[n]; 
    for (int i = 0; i < n; i++) {
        dist[i] = inf; 
        vis[i] = 0; 
    }
    dist[src] = 0; 
    for (int c = 0; c < n - 1; c++) {
        int u = findMin(dist, vis);
        if (u == -1) return; 
        vis[u] = 1; 
        for (int v = 0; v < n; v++) {
            if (!vis[v] && adj[u][v] && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v]; 
            }
        }
    }
}

int main() {
    printf("Enter number of vertex : "); 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]); 
        }
    }
    int src; 
    printf("Enter source : "); 
    scanf("%d", &src); 
    int dist[n]; 
    dijkstra(src, dist);
    printf("Dist Matrix :\n"); 
    for (int i = 0; i < n; i++) printf("%d ", dist[i]);
    printf("\n"); 
}