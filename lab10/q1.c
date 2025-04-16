#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createnode(int value){
  struct node *newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

struct node *insert(struct node **root,int value){
  if(*root == NULL){
    *root = createnode(value);
  }
  else if(value <= (*root)->data){
    (*root)->left = insert(&((*root)->left), value);
  }
  else{
    (*root)->right = insert(&((*root)->right), value);
  }
  return *root;

}

void inorder(struct node *root){
  if(root != NULL){
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void preorder(struct node *root){
  if(root != NULL){
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
 
void postorder(struct node *root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main(){
  struct node *root = NULL;
  root = insert(&root, 5);
  root = insert(&root, 3);
  root = insert(&root, 7);
  root = insert(&root, 1);
  root = insert(&root, 9);

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  
  return 0;
}
