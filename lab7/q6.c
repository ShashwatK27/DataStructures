#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    if (top == 99) return;
    stack[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

int isBalanced(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') push(str[i]);
        else if (str[i] == ')' && pop() != '(') return 0;
        else if (str[i] == '}' && pop() != '{') return 0;
        else if (str[i] == ']' && pop() != '[') return 0;
    }
    return top == -1;
}

int main() {
    char str[100];
    printf("Enter an expression: ");
    scanf("%s", str);
    if (isBalanced(str)) printf("Balanced!\n");
    else printf("Not Balanced!\n");
    return 0;
}
