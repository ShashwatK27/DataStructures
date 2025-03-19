#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = head;
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        return newNode;
    }
    
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position == 0) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* current = head;
    newNode->data = data;

    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds.\n");
        free(newNode);
        return head;
    }

    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 5);
    
    printf("List after inserting at beginning: ");
    printList(head);

    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 25);
    
    printf("List after inserting at end: ");
    printList(head);

    head = insertAtPosition(head, 15, 2);
    
    printf("List after inserting at position 2: ");
    printList(head);

    return 0;
}
