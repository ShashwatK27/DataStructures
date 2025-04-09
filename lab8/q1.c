#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    while (last->next != NULL)
        last = last->next;
    
    last->next = newNode;
}


void removeDuplicates(struct Node* head) {
    struct Node *current, *prev, *temp;
    current = head;
    
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}


void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 10);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 30);
    insert(&head, 50);
    
    printf("Original list:\n");
    printList(head);
    
    removeDuplicates(head);
    
    printf("List after removing duplicates:\n");
    printList(head);
    
    return 0;
}