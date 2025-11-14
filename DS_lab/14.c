#include <stdio.h>
#include <string.h>
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

// Check precedence
int precedence(char x) {
    if(x == '^') return 3;
    if(x == '*' || x == '/') return 2;
    if(x == '+' || x == '-') return 1;
    return 0;
}

// Reverse string & swap brackets
void reverse(char *exp) {
    int i, j;
    char temp;
    for(i = 0, j = strlen(exp)-1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
    for(i = 0; exp[i]; i++) {
        if(exp[i] == '(') exp[i] = ')';
        else if(exp[i] == ')') exp[i] = '(';
    }
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];
    int i = 0, j = 0;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    reverse(infix); // Step 1: Reverse infix

    while(infix[i] != '\0') {

        if(isalnum(infix[i]))  // Operand
            postfix[j++] = infix[i];

        else if(infix[i] == '(')
            push(infix[i]);

        else if(infix[i] == ')') {
            while(stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else { // Operator
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
        i++;
    }

    while(top != -1)  // remaining operators
        postfix[j++] = pop();

    postfix[j] = '\0';

    reverse(postfix);  // Step 3: Reverse postfix -> prefix
    strcpy(prefix, postfix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
