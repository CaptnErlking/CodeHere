#include<stdio.h>
#include<stdlib.h>
#define max 100

int adj[max][max];
int n; 

typedef struct {
    int u, v, w; 
} edge;

edge e[max * max]; 

int cmp(const void * a, const void * b) {
    edge *x = (edge*)a;
    edge *y = (edge*)b;
    return x -> w - y -> w; 
}

int find(int x, int parent[]) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent); 
    }
    return parent[x];
}

void unio(int u, int v, int parent[]) {
    int pu = parent[u]; 
    int pv = parent[v]; 
    parent[pu] = pv; 
}

void kruskal() {
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j]) {
                e[k].u = i; 
                e[k].v = j; 
                e[k].w = adj[i][j];
                k++; 
            }
        }
    }
    qsort(e, k, sizeof(edge), cmp); 
    int parent[n]; 
    for (int i = 0; i < n; i++) parent[i] = i; 
    int count = 0; 
    for (int i = 0; i < k && count < n - 1; i++) {
        int u = e[i].u; 
        int v = e[i].v; 
        int w = e[i].w; 
        if (find(u, parent) != find(v, parent)) {
            printf("%d - %d : (%d)\n", u, v, w); 
            unio(u, v, parent);
            count++; 
        }
    }
}

int main() {
    printf("Enter the number of Vertices : ");
    scanf("%d", &n); 
    printf("Enter the adj matrix : \n"); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]); 
        }
    }
    printf("MST:\n"); 
    kruskal(); 
}