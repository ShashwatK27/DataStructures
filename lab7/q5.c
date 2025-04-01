#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char value) {
    if (top == 99) {
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = value;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1;
    } else {
        char data = stack[top];
        top--;
        return data;
    }
}

char peek() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top];
    }
}

int rank(char a) {
    switch (a) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

void ConvertToPostfix(char *a, char *postfix) {
    int n = strlen(a);
    int j = 0;

    for (int i = 0; i < n; i++) {
        char b = a[i];

        if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z') || (b >= '0' && b <= '9')) {
            postfix[j++] = b;
        } else if (b == '(') {
            push(b);
        } else if (b == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                printf("Error: Unmatched parentheses\n");
                return;
            }
            pop();     
        } else {
            while (top != -1 && rank(b) <= rank(peek())) {
                postfix[j++] = pop();
            }
            push(b);
        }
    }

    while (top != -1) {
        if (peek() == '(') {
            printf("Error: Unmatched parentheses\n");
            return;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  
}

int main() {
    char expression[100];
    char postfix[100];

    printf("Enter the expression: ");
    scanf("%s", expression);

    ConvertToPostfix(expression, postfix);
    printf("\nThe postfix expression is: %s\n", postfix);

    return 0;
}
