#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lab {
    char name[50];
    int computers;
    struct Lab *next;   // Circular link
};

struct Lab *rear = NULL;   // Points to last node in circular queue

// Insert Lab (Enqueue)
void insert(char labName[], int comp) {
    struct Lab *newNode = (struct Lab*)malloc(sizeof(struct Lab));
    strcpy(newNode->name, labName);
    newNode->computers = comp;

    if(rear == NULL) {                // Queue empty
        rear = newNode;
        rear->next = rear;
    } 
    else {
        newNode->next = rear->next;   // Insert after rear
        rear->next = newNode;
        rear = newNode;               // Update rear to new node
    }
    printf("Inserted: %s (%d computers)\n", labName, comp);
}

// Delete Lab (Dequeue)
void delete() {
    if(rear == NULL) {
        printf("Queue Underflow! No labs to delete.\n");
        return;
    }

    struct Lab *temp = rear->next;    // First node

    if(rear == temp) {                // Only one node
        printf("Deleted: %s (%d computers)\n", temp->name, temp->computers);
        rear = NULL;
    }
    else {
        rear->next = temp->next;      // Remove first
        printf("Deleted: %s (%d computers)\n", temp->name, temp->computers);
    }

    free(temp);
}

// Display Queue
void display() {
    if(rear == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Lab *temp = rear->next;    // Start from front
    printf("\nCircular Queue:\n");
    do {
        printf("Lab Name: %-15s  Computers: %d\n", temp->name, temp->computers);
        temp = temp->next;
    } while(temp != rear->next);
}

int main() {
    int choice, comp;
    char name[50];

    while(1) {
        printf("\n1. Insert Lab\n2. Delete Lab\n3. Display Labs\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Lab Name: ");
                scanf("%s", name);
                printf("Enter Number of Computers: ");
                scanf("%d", &comp);
                insert(name, comp);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
