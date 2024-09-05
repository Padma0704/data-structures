#include <stdio.h>
#include <limits.h>

#define V 10 
int minDistance(int dist[], int visited[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++)
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    return minIndex;
}
void printSolution(int dist[], int numVertices) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < numVertices; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}
void dijkstra(int graph[V][V], int src, int numVertices) {
    int dist[V];   
    int visited[V]; 
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited, numVertices);
        visited[u] = 1;
        for (int v = 0; v < numVertices; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, numVertices);
}
int main() {
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    int graph[V][V];
    printf("Enter the adjacency matrix of the graph (enter 0 if there is no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    printf("Shortest paths from vertex %d:\n", src);
    dijkstra(graph, src, numVertices);
    return 0;
}

