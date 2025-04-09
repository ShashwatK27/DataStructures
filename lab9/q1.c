#include<stdio.h>
#include<stdlib.h>

int queue[50];
int rear=-1,front=-1;

void enqueue(int data)
{
  if(rear==49){
    printf("Queue is full\n");
  }
    else{
      if(front==-1){
        front=0;
      }
      rear++;
      queue[rear]=data;
      printf("Element inserted\n");
    }
}

void dequeue()
{
  if(front==-1){
    printf("Queue is empty\n");
  }
  else{
    printf("Element deleted is %d\n",queue[front]);
    front++;
    if(front>rear){
      front=rear=-1;
    }
  }
}

int main()
{
  int choice,data;
  while(1){
    printf("1. Insert\n2. Delete\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}


