#include<stdio.h>
#define max 100
int adj[max][max]; 
int stk[max];
int vis[max]; 
int top = -1; 
int n; 

int pop() {
    return stk[top--]; 
}

void push(int x) {
    stk[++top] = x; 
}

void dfs(int u) {
    vis[u] = 1; 
    int v;
    for (v = 0; v < n; v++) {
        if (adj[u][v] == 1 && !vis[v]) {
            dfs(v); 
        }
    }
    push(u);
}

int main() {
    printf("Enter the number of Vertices : "); 
    scanf("%d", &n); 
    printf("Enter the adj mat :\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &adj[i][j]); 
    
    printf("Topo sort : \n"); 

    for (int i = 0; i < n; i++) vis[i] = 0; 
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i); 
        }
    }
    while (top != -1) printf("%d ", pop()); 
    printf("\n");
}