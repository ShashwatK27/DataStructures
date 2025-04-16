#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};


struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
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


int findHeight(struct node* root) {
    if (root == NULL)
        return -1;  
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int findDepth(struct node* root, int value, int depth) {
    if (root == NULL)
        return -1;  

    if (root->data == value)
        return depth;

    
    int left = findDepth(root->left, value, depth + 1);
    if (left != -1)
        return left;

    
    return findDepth(root->right, value, depth + 1);
}


void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
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

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    int val = 7;
    int depth = findDepth(root, val, 0);
    if (depth != -1)
        printf("Depth of node with value %d: %d\n", val, depth);
    else
        printf("Node %d not found in the tree.\n", val);

    return 0;
}
