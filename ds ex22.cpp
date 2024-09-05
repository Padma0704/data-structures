#include <stdio.h>
#include <stdlib.h>
void DFS(int graph[][10], int startVertex, int visited[], int numVertices) {
    visited[startVertex] = 1;
    printf("%d ", startVertex);
    for (int i = 0; i < numVertices; i++) {
        if (graph[startVertex][i] == 1 && !visited[i]) {
            DFS(graph, i, visited, numVertices);
        }
    }
}
int main() {
    int numVertices;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);
    int graph[10][10];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int visited[10] = {0};  

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    DFS(graph, startVertex, visited, numVertices);

    return 0;
}

