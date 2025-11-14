#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adjList[20];
int visited[20];

// Create new adjacency list node
struct Node* createNode(int v) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Insert edge (Undirected Graph)
void insertEdge(int src, int dest) {
    struct Node *newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// DFS Traversal
void DFS(int v) {
    struct Node *temp;
    printf("%d ", v);
    visited[v] = 1;

    temp = adjList[v];
    while(temp != NULL) {
        if(!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int vertices, edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(int i=0; i<vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (src dest):\n");
    for(int i=0; i<edges; i++) {
        scanf("%d %d", &src, &dest);
        insertEdge(src, dest);
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}
