#include <stdio.h>
#define MAX 20

int graph[MAX][MAX], indegree[MAX], queue[MAX];
int front = -1, rear = -1, n;

void enqueue(int item) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void topologicalSort() {
    int i, j, count = 0, node;

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (graph[j][i] == 1)
                indegree[i]++;
        }
    }
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Ordering: ");

    while (front <= rear) {
        node = dequeue();
        printf("%d ", node);
        count++;

        for (i = 0; i < n; i++) {
            if (graph[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    if (count != n)
        printf("\nGraph contains a cycle. Topological ordering not possible.");
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    topologicalSort();
    return 0;
}
