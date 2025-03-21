#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* CreateNode(int data) {
    struct node* nnode = (struct node*)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = NULL;
    nnode->prev = NULL;
    return nnode;
}

void InitStack(struct node** top) {
    *top = NULL;
}

void push(struct node** top, int value) {
    struct node* nnode = CreateNode(value);
    nnode->next = *top;
    if (*top != NULL) {
        (*top)->prev = nnode;
    }
    *top = nnode;
    printf("%d pushed onto stack\n", value);
}

int pop(struct node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        struct node* temp = *top;
        int poppedValue = temp->data;
        *top = (*top)->next;
        if (*top != NULL) {
            (*top)->prev = NULL;
        }
        free(temp);
        return poppedValue;
    }
}

int peek(struct node** top) {
    if (*top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    } else {
        return (*top)->data;
    }
}

void display(struct node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        struct node* temp = *top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct node* stack;
    InitStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    printf("Popped element: %d\n", pop(&stack));
    display(&stack);

    printf("Top element is: %d\n", peek(&stack));
    display(&stack);

    return 0;
}
