#include<stdio.h>
#include<stdlib.h>

struct Stack{
  int a[10];
  int top;
};

void InitStack(struct Stack *stack){
  stack->top=-1;
}

void push(struct Stack *stack,int value){
  if(stack->top==9){
    printf("Stack is overloaded!");
  }
  else{
    stack->a[++stack->top]=value;
    printf("The value %d has been pushed\n",value);
  }
}

int pop(struct Stack *stack){
  if(stack->top==-1){
    printf("Stack is underloaded!");
    return -1;
  }
  else{
    int poppedvalue=stack->a[stack->top--];
    return poppedvalue;
  }
}

int peek(struct Stack *stack){
  if(stack->top==-1){
    printf("Stack is empty!");
    return -1;
  }
  else{
    return stack->a[stack->top];
  }
}

void print(struct Stack *stack){
  if(stack->top==-1){
    printf("Stack is empty!");
  }
  else{
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->a[i]);
    }
    printf("\n");
  }
}

int main(){
  struct Stack stack;
  InitStack(&stack);
  
  push(&stack,25);
  push(&stack,65);
  push(&stack,59);
  push(&stack,19);

  print(&stack);

  printf("\nPopped value: %d\n",pop(&stack));
  print(&stack);

  printf("\nTop element is:%d\n",peek(&stack));
  print(&stack);

  return 0;
  
}