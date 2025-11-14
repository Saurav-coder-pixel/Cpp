#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int roll;
    char name[50];
    struct student *next;
};

// Function to insert node at a given position
void insertAtPos(struct student **head, int roll, char name[], int pos) {
    struct student *newNode = (struct student*) malloc(sizeof(struct student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (pos == 1) {  // Insert at beginning
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct student *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by roll number
void deleteByRoll(struct student **head, int roll) {
    struct student *temp = *head, *prev = NULL;

    // If head needs deletion
    if (temp != NULL && temp->roll == roll) {
        *head = temp->next;
        free(temp);
        printf("Student with roll %d deleted.\n", roll);
        return;
    }

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Roll number not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Student with roll %d deleted.\n", roll);
}

// Function to reverse linked list
void reverseList(struct student **head) {
    struct student *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to display list
void display(struct student *head) {
    struct student *temp = head;
    printf("\nStudent List:\n");
    while (temp != NULL) {
        printf("Roll: %d  Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    struct student *head = NULL;
    int choice, roll, pos;
    char name[50];

    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student by Roll No\n");
        printf("3. Reverse List\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertAtPos(&head, roll, name, pos);
                break;

            case 2:
                printf("Enter roll to delete: ");
                scanf("%d", &roll);
                deleteByRoll(&head, roll);
                break;

            case 3:
                reverseList(&head);
                printf("Linked list reversed.\n");
                break;

            case 4:
                display(head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
