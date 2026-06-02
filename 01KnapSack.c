#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    int selected[n];
    int count = 0;
    int w = W;

    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[count++] = i;
            w -= wt[i - 1];
        }
    }

    printf("Selected items:\n");

    for (int i = count - 1; i >= 0; i--) {
        int idx = selected[i] - 1;
        printf("Item %d (Value = %d, Weight = %d)\n",
               selected[i], val[idx], wt[idx]);
    }

    return 0;
}
