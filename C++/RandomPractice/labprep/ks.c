#include<stdio.h>

void ks(int n, int wt[], int v[], int cap) {
    int dp[n + 1][cap + 1]; 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= cap; w++) {
            if (i == 0 || w == 0) dp[i][w] = 0; 
            else if (wt[i - 1] <= w) dp[i][w] = (v[i - 1] + dp[i - 1][w - wt[i - 1]] > dp[i - 1][w]) ?  
                                                 v[i - 1] + dp[i - 1][w - wt[i - 1]] : dp[i - 1][w]; 
            else dp[i][w] = dp[i - 1][w]; 
        }
    }
    printf("Max Value : %d\n", dp[n][cap]); 
}

int main() {
    int n; 
    printf("Enter the number of items : "); 
    scanf("%d", &n); 
    int v[n]; 
    int wt[n]; 
    printf("Enter the the wt : val\n"); 
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &v[i]); 
    }
    int w; 
    printf("Enter the cap : ");
    scanf("%d", &w); 
    ks(n, wt, v, w); 
}