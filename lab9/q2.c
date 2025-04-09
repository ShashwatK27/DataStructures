#include<stdio.h>
#include<stdlib.h>

struct queue{
  int data;
  struct queue *next;
}*rear=NULL,*front=NULL;

void enqueue(int data){
  struct queue *temp;
  temp=(struct queue*)malloc(sizeof(struct queue));
  temp->data=data;
  temp->next=NULL;
  if(front==NULL){
    front=rear=temp;
  }
  else{
    rear->next=temp;
    rear=temp;
  }
}

void dequeue(){
  struct queue *temp;
  if(front==NULL){
    printf("Queue is empty\n");
  }
  else{
    temp=front;
    front=front->next;
    free(temp);
  }
}

void display(){
  struct queue *temp;
  temp=front;
  while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("\n");
}

int main(){
  enqueue(1);
  enqueue(2);
  enqueue(3);
  enqueue(4);
  enqueue(5);
  display();
  dequeue();
  display();
  return 0;
}
