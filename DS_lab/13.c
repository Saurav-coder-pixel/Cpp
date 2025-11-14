#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top = -1;

// Push
void push(char x) {
    stack[++top] = x;
}

// Pop
char pop() {
    return stack[top--];
}

// Check priority of operators
int precedence(char x) {
    if(x == '^')
        return 3;
    if(x == '*' || x == '/')
        return 2;
    if(x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;
    char x;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0') {
        // Operand → directly add to postfix
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // Left bracket → push
        else if(infix[i] == '(') {
            push(infix[i]);
        }
        // Right bracket → pop till '('
        else if(infix[i] == ')') {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        }
        // Operator
        else {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }

    // Pop remaining operators
    while(top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
