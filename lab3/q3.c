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

struct Node* createList(int size) {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* current = NULL;
    for (int i = 0; i < size; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = i + 1;  // Just to populate the list with data
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

struct Node* concatenateLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = list2;
    return list1;
}

int main() {
    int n = 3, m = 2;
    struct Node* list1 = createList(n);
    struct Node* list2 = createList(m);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct Node* concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    printList(concatenatedList);

    return 0;
}
