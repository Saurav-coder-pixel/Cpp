#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int roll) {
    if(top == MAX - 1) {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    stack[++top] = roll;
    printf("Pushed: %d\n", roll);
}

// Pop function
int pop() {
    if(top == -1) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    }
    return stack[top--];
}

// Display function
void display() {
    if(top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements (Top to Bottom):\n");
    for(int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    int choice, roll, popped;

    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter roll number to push: ");
                scanf("%d", &roll);
                push(roll);
                break;

            case 2:
                popped = pop();
                if(popped != -1)
                    printf("Popped: %d\n", popped);
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
