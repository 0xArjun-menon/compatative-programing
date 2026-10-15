#include<stdio.h>
#define MAX 100
#define INF 99999
int graph [MAX][MAX];
int residual [MAX][MAX];
int parent[MAX];
int visited[MAX];
int n;

int bfs(int source, int sink){
    int queue[MAX];
    int front = 0, rear = 0;
    int u, v;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        parent[i] = -1;
    }
    queue[rear++] = source;
    visited[source] = 1;
    while (front < rear) {
        u = queue[front++];
        for (v = 0; v < n; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                visited[v] = 1;
                parent[v] = u;
                if (v == sink) {
                    return 1;
                }
                queue[rear++] = v;
            }
        }
    }
    return 0;
}

int edmondsKarp(int source, int sink){
    int maxFlow = 0;
    int pathFlow;
    int u, v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            residual[i][j] = graph[i][j];
        }
    }
    while (bfs(source, sink)) {
        pathFlow = INF;
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            if (pathFlow > residual[u][v]) {
                pathFlow = residual[u][v];
            }
        }
        for (v = sink; v != source; v = parent[v]) {
            u = parent[v];
            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}
