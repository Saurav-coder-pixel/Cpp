#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int full= MAX-1;
int roll_stack[MAX];
int top = -1;

void PUSH(int ele) {
    if (top == full) {
        printf("\nOVERFLOW! Stack is full.\n");
        return;
    }
    roll_stack[++top] = ele;
}

int POP() {
    if (top == -1) {
        printf("\nUNDERFLOW! Stack is empty.\n");
        return -1;
    }
    return roll_stack[top--];
}

void DISPLAY_ARRAY_STACK() {
    if (top == -1) {
        printf("\nSTACK IS EMPTY. NOTHING TO DISPLAY.\n");
        return;
    }
    printf("\nSTACK CONTENTS:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d  ", roll_stack[i]);
    }
    printf("\n");
}

int main() {
    char ch;
    int cho, item;

    do {
        printf("\nCHOICE:\n1 PUSH\n2 POP\n3 DISPLAY\n4 EXIT\nEnter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1:
                printf("ENTER ROLL NUMBER: ");
                scanf("%d", &item);
                PUSH(item);
                break;
            case 2:
                item = POP();
                if (item != -1)
                    printf("ELEMENT POPPED: %d\n", item);
                break;
            case 3:
                DISPLAY_ARRAY_STACK();
                break;
            case 4:
                exit(0);
            default:
                printf("\nINVALID CHOICE\n");
        }

        printf("\nDO YOU WANT TO CONTINUE (Y/N): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}