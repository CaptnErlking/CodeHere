#include <stdio.h>
#include <stdlib.h>

struct edge {
    int src;
    int dst;
    int wt;
};

int compareEdges(const void *a, const void *b) {
    return ((struct edge *)a)->wt - ((struct edge *)b)->wt;
}

int find(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return find(parent, parent[v]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(struct edge e[], int V, int E) {
    qsort(e, E, sizeof(struct edge), compareEdges);

    int parent[V], rank[V];
    struct edge MST[V - 1];
    int mstSz = 0, total = 0;

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    for (int i = 0; i < E && mstSz < V - 1; i++) {
        struct edge curr = e[i];
        int rootSrc = find(parent, curr.src);
        int rootDst = find(parent, curr.dst);

        if (rootSrc != rootDst) {
            MST[mstSz++] = curr;
            unionSets(parent, rank, rootSrc, rootDst);
            total += curr.wt;
        }
    }

    printf("Here is the minimum spanning tree:\n");
    for (int i = 0; i < mstSz; i++) {
        printf("%d -> %d ( %d )\n", MST[i].src, MST[i].dst, MST[i].wt);
    }
    printf("The total weight of the minimum spanning tree is %d\n", total);
}

int main() {
    int V, E;
    printf("Enter the number of Vertices and Edges:\n");
    scanf("%d %d", &V, &E);

    struct edge *e = (struct edge *)malloc(E * sizeof(struct edge));
    printf("Enter edges (src dst wt):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &e[i].src, &e[i].dst, &e[i].wt);
    }

    kruskal(e, V, E);
    free(e);

    return 0;
}
