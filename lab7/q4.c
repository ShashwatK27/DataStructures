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

int isPalindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) 
    push(str[i]);
    for (int i = 0; i < len; i++) 
    if (str[i] != pop()) 
    return 0;
    return 1;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)) 
    printf("Palindrome!\n");
    else 
    printf("Not a palindrome!\n");
    return 0;
}
