#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[20];
int visited[20];
int queue[20];
int front = -1, rear = -1;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Insert edge (undirected graph)
void insertEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Enqueue function
void enqueue(int v) {
    if(rear == 19) return;
    if(front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue function
int dequeue() {
    if(front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS Traversal
void BFS(int start) {
    for(int i = 0; i < 20; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while(front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        struct Node* temp = adjList[current];
        while(temp) {
            if(!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main() {
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        insertEdge(src, dest);
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
