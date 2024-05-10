#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct stack
{
  int top;
  int size;
  int *arr;
};

struct stack *createstack(int capacity)
{
  struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));
  s1->top = -1;
  s1->size = capacity;
  s1->arr = (int *)malloc(s1->size * (sizeof(int)));
  return s1;
}

bool IsEmpty(struct stack *stack)
{
  if (stack->top == -1)
  {
    return true;
  }
  return false;
}

bool IsFull(struct stack *stack)
{
  if (stack->top == stack->size - 1)
  {
    return true;
  }
  return false;
}
void push(struct stack *stack, int value)
{
  if (IsFull(stack) == true)
  {
    printf("Stack Overflow Error");
    return;
  }
  stack->top++;
  stack->arr[stack->top] = value;
  return;
}

int pop(struct stack *stack)
{
  if (IsEmpty(stack) == false)
  {
    int rem = stack->arr[stack->top];
    stack->top--;
    return rem;
  }
  printf("Stack Underflow Error");
}

void printstack(struct stack *stack)
{
  int i = 0;
  while (i <= stack->top)
  {
    printf("\n");
    printf("%d", stack->arr[i]);
    i++;
  }
}
int main()
{
  struct stack *S = createstack(10);
  push(S, 1);
  push(S, 2);
  push(S, 3);
  pop(S);
  push(S, 100);
  printstack(S);
}