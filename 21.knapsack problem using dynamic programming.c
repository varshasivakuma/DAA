#include<stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int i, j;
    int n; 
    int capacity; 
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    int weight[n+1], value[n+1];
    printf("Enter the weight and value of each item:\n");
    for (i = 1; i <= n; i++) {
        printf("Item %d: ", i);
        scanf("%d %d", &weight[i], &value[i]);
    }
    int dp[n+1][capacity+1];
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weight[i] <= j)
                dp[i][j] = max(value[i] + dp[i-1][j-weight[i]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    int includedItems[n+1];
    i = n;
    j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            includedItems[i] = 1;
            j -= weight[i];
        } else {
            includedItems[i] = 0;
        }
        i--;
    }
    printf("\nItems included in the knapsack are:\n");
    for (i = 1; i <= n; i++) {
        if (includedItems[i])
            printf("Item %d\n", i);
    }
    printf("\nMaximum value that can be obtained: %d\n", dp[n][capacity]);

    return 0;
}
