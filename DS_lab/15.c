#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int queue[MAX];
int front = -1, rear = -1;

// Insert (Enqueue)
void insert(int emp) {
    if(rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert.\n");
        return;
    }

    if(front == -1) front = 0;
    queue[++rear] = emp;

    printf("Inserted Employee No: %d\n", emp);
}

// Delete (Dequeue)
int delete() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
        return -1;
    }

    return queue[front++];
}

// Display queue
void display() {
    if(front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue Elements (Front to Rear):\n");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Main function
int main() {
    int choice, emp, del;

    while(1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert (Enqueue)\n2. Delete (Dequeue)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Employee Number to insert: ");
                scanf("%d", &emp);
                insert(emp);
                break;

            case 2:
                del = delete();
                if(del != -1)
                    printf("Deleted Employee No: %d\n", del);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
