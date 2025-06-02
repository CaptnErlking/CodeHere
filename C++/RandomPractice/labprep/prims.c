#include<stdio.h>
#include<limits.h>
#define max 100
int adj[max][max]; 
int n; 

int wmin(int key[], int mst[]) {
    int mi = -1;
    for (int i = 0; i < n; i++) {
        if (!mst[i] && (mi == -1 || key[i] < key[mi])) {
            mi = i; 
        }
    }
    return mi; 
}

void prims() {
    int mst[n]; 
    int p[n]; 
    int key[n]; 
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX; 
        mst[i] = 0; 
    }
    key[0] = 0;  
    p[0] = -1; 
    for (int c = 0; c < n - 1; c++) {
        int u = wmin(key, mst); 
        mst[u] = 1; 
        for (int i = 0; i < n; i++) {
            if (adj[u][i] && !mst[i] && adj[u][i] < key[i]) {
                key[i] = adj[u][i]; 
                p[i] = u; 
            }
        }
    }
    printf("Edges of mst : \n"); 
    for (int i = 1; i < n; i++) {
        printf("%d - %d : (%d)\n", p[i], i, adj[p[i]][i]); 
    }
}

int main() {
    printf("Enter the number of Vertices : "); 
    scanf("%d", &n); 
    printf("Enter the adj mat :\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]); 

    prims(); 
    printf("\n");
}
