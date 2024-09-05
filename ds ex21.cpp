#include <stdio.h>
#include <stdlib.h>
struct QueueNode {
    int data;
    struct QueueNode* next;
};
struct Queue {
    struct QueueNode *front, *rear;
};
struct QueueNode* newQueueNode(int data) {
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
void enqueue(struct Queue* queue, int data) {
    struct QueueNode* node = newQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}
int dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return -1;
    struct QueueNode* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return data;
}
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}
void BFS(int graph[][10], int startVertex, int numVertices) {
    int visited[10] = {0};  
    struct Queue* queue = createQueue();
    visited[startVertex] = 1;
    enqueue(queue, startVertex);
    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);
        for (int i = 0; i < numVertices; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(queue, i);
            }
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

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);
    BFS(graph, startVertex, numVertices);

    return 0;
}

