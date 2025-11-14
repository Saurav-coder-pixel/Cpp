#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct College {
    int code;
    char name[50];
    struct College *next;
};

struct College *last = NULL;   // Circular Linked List pointer

// Create node
struct College* createNode(int code, char name[]) {
    struct College *newNode = (struct College*)malloc(sizeof(struct College));
    newNode->code = code;
    strcpy(newNode->name, name);
    newNode->next = newNode;
    return newNode;
}

// Insert at front
void insertFront(int code, char name[]) {
    struct College *newNode = createNode(code, name);

    if(last == NULL) {
        last = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    printf("Node inserted at front.\n");
}

// Delete at end
void deleteEnd() {
    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct College *temp = last->next, *prev = NULL;

    // If only one node
    if(last->next == last) {
        free(last);
        last = NULL;
        printf("Last node deleted.\n");
        return;
    }

    // Traverse to second last node
    while(temp != last) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = last->next;
    free(last);
    last = prev;
    printf("Last node deleted.\n");
}

// Display list
void display() {
    if(last == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct College *temp = last->next;
    printf("\nCollege List:\n");
    do {
        printf("Code: %d | Name: %s\n", temp->code, temp->name);
        temp = temp->next;
    } while(temp != last->next);
}

int main() {
    int choice, code;
    char name[50];

    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front\n2. Delete at End\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch(choice) {
            case 1:
                printf("Enter College Code: ");
                scanf("%d", &code);
                getchar(); // clear newline

                printf("Enter College Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline

                insertFront(code, name);
                break;

            case 2:
                deleteEnd();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
