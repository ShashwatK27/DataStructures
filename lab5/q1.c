#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

int main(){
  int input=1;
  struct node *head,*temp,*nnode;
  head=NULL;
  while(input==1){
  nnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&nnode->data);
  nnode->next=NULL;
  if(head==NULL){
    head=nnode;
    temp=nnode;
  }
  else{
    temp->next=nnode;
    temp=nnode;
  }
  printf("Do you want to add more data?(if yes then press 1)\n");
  scanf("%d",&input);
  }

  temp=head;
  while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->next;
  }

  temp=head;
  int min;
  min=32000;
  while(temp!=0){
    if(min>temp->data){
      min=temp->data;
    }
    temp=temp->next;
  }
  temp=head;
  temp->data=min;

  printf("The new linked list is:");
  temp=head;
  while(temp!=0){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  return 0;
}