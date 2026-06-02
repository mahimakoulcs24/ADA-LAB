#include <stdio.h>

#define INF 99999

void floydWarshall(int V, int dist[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void printMatrix(int V, int dist[V][V]) {
    printf("\nShortest Distance between each pair:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int dist[V][V];

    printf("Enter the adjacency matrix:\n");
    printf("(Use %d for no direct edge)\n", INF);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    floydWarshall(V, dist);

    printMatrix(V, dist);

    return 0;
}
