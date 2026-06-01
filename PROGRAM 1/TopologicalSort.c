#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void topologicalSort(int V, int adj[MAX][MAX]) {
    int indegree[MAX] = {0};
    int topo[MAX];
    int count = 0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
     while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;
        for (int j = 0; j < V; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }
    if (count != V) {
        printf("Topological ordering not possible (Cycle exists)\n");
        return;
    }
    printf("Topological Sorting : ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}
int main() {
    int V, E;
    int adj[MAX][MAX] = {0};

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort(V, adj);
    return 0;
}
