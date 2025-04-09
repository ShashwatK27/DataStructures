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


void rotateRight(struct Node** head, int k) {
    if (*head == NULL || k == 0) return;

    struct Node *tail, *prev, *temp;
    
    for (int i = 0; i < k; i++) {
        if (*head == NULL || (*head)->next == NULL) return; 
        
        tail = *head;
        prev = NULL;

        
        while (tail->next != NULL) {
            prev = tail;
            tail = tail->next;
        }

        
        prev->next = NULL; 
        tail->next = *head; 
        *head = tail; 
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
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    
    printf("Original list:\n");
    printList(head);
    
    int k = 2;
    rotateRight(&head, k);
    
    printf("List after rotating %d times to the right:\n", k);
    printList(head);
    
    return 0;
}
