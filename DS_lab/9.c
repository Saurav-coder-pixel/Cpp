#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[30];
    float salary;
    struct Employee *prev, *next;
};

struct Employee *head = NULL;

// Function to create new node
struct Employee* createNode(int id, char name[], float salary) {
    struct Employee *newNode = (struct Employee*)malloc(sizeof(struct Employee));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int id, char name[], float salary) {
    struct Employee *newNode = createNode(id, name, salary);

    if(head == NULL) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Delete at end
void deleteEnd() {
    struct Employee *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(head->next == NULL) {  // Only one node
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Display list
void displayList() {
    struct Employee *temp = head;

    if(temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nEmployee List:\n");
    while(temp != NULL) {
        printf("ID: %d | Name: %s | Salary: %.2f\n",
                temp->id, temp->name, temp->salary);
        temp = temp->next;
    }
}

int main() {
    int choice, id;
    char name[30];
    float salary;

    while(1) {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Front\n2. Delete at End\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ID, Name, Salary: ");
                scanf("%d %s %f", &id, name, &salary);
                insertFront(id, name, salary);
                break;

            case 2:
                deleteEnd();
                break;

            case 3:
                displayList();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
