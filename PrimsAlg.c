#include <stdio.h>
#define MAX 100
#define INF 999999

int main() {
    int n, cost[MAX][MAX];
    int visited[MAX] = {0};
    int minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j) {
                cost[i][j] = INF;
            }
        }
    }

    visited[0] = 1; // Start from vertex 0

    int edges = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            printf("%d -> %d  Cost = %d\n", u, v, min);
            minCost += min;
            visited[v] = 1;
            edges++;
        }
    }
    printf("\nMinimum Cost = %d\n", minCost);
    return 0;
}
