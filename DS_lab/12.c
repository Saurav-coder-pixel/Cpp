#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student
struct Student {
    int roll;
    char name[50];
    struct Student *next;
};

struct Student *top = NULL;   // Stack top pointer

// Push function
void push(int roll, char name[]) {
    struct Student *newNode = (struct Student*)malloc(sizeof(struct Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);

    newNode->next = top;  // Insert at top
    top = newNode;

    printf("Pushed -> Roll: %d, Name: %s\n", roll, name);
}

// Pop function returns popped structure
struct Student pop() {
    struct Student temp = {-1, ""};

    if(top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return temp;
    }

    struct Student *del = top;
    temp = *top;          // Copy data to return
    top = top->next;      // Move top down
    free(del);

    return temp;
}

// Display function
void display() {
    if(top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Student *temp = top;
    printf("\nStack (Top to Bottom):\n");
    while(temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice, roll;
    char name[50];
    struct Student popped;

    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Roll & Name: ");
                scanf("%d %s", &roll, name);
                push(roll, name);
                break;

            case 2:
                popped = pop();
                if(popped.roll != -1)
                    printf("Popped -> Roll: %d, Name: %s\n", popped.roll, popped.name);
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
