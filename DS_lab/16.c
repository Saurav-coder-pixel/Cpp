#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int empNo;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

// Insert into queue
void insert(int emp) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->empNo = emp;
    newNode->next = NULL;

    if(rear == NULL) {        // Queue empty
        front = rear = newNode;
    } 
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted: %d\n", emp);
}

// Delete from queue
int delete() {
    if(front == NULL) {       // Queue empty
        printf("Queue Underflow!\n");
        return -1;
    }

    struct Node *temp = front;
    int val = temp->empNo;

    front = front->next;
    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

// Display queue
void display() {
    if(front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Queue: ");
    while(temp != NULL) {
        printf("%d ", temp->empNo);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, emp, del;

    while(1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Employee Number: ");
                scanf("%d", &emp);
                insert(emp);
                break;

            case 2:
                del = delete();
                if(del != -1)
                    printf("Deleted: %d\n", del);
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
