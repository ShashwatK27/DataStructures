//write a code of linklist
//traverse the link list and print content of every node
//create two link list having size n,m respective .Derive 3rd link list by concatenating link list
//insert a node at the beginning,end and specefic point of the linkedlist

#include<stdio.h>
#include<stdlib.h>

struct node{
  int a;
  struct node *next;
};

struct node *head=0;

void insert(int n){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->a=n;
  temp->next=head;
  head=temp;
}

int main(){
 insert(10);
 insert(20);
 insert(30);


  if(head==0){
    printf("LINKEDLIST IS EMPTY");
  }

  struct node *p=head;

  while(p!=0){
    printf("%d",p->a);
    p=p->next;
  }

  return 0;
}