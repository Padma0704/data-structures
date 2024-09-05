#include <stdio.h>
#include <limits.h>

#define V 10  
int minKey(int key[], int mstSet[], int numVertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < numVertices; v++)
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    return minIndex;
}
void printMST(int parent[], int graph[V][V], int numVertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[V][V], int numVertices) {
    int parent[V];  
    int key[V];     
    int mstSet[V];  
    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;      
    parent[0] = -1;  
    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;
        for (int v = 0; v < numVertices; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    printMST(parent, graph, numVertices);
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
    printf("The Minimum Spanning Tree (MST) for the graph is:\n");
    primMST(graph, numVertices);

    return 0;
}

