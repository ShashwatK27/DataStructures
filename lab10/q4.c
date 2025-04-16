#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};

int n;


struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    n++;
    return newNode;
}


struct node* insert(struct node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        
    } else if (value <= (*root)->data) {
        (*root)->left = insert(&((*root)->left), value);
        
    } else {
        (*root)->right = insert(&((*root)->right), value);
        
    }
    return *root;
}


int countLeafNodes(struct node* root) {
    
    if (root == NULL)
        return 0;

    
    if (root->left == NULL && root->right == NULL)
        return 1;

   
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}



int main() {
    struct node* root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 20);

   

    int leafCount = countLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    printf("Number of internal nodes: %d\n", n-leafCount);

    return 0;
}
