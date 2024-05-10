#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct queue
{
  int rear;
  int front;
  int size;
  int *arr;
};

struct queue *createqueue(int capacity)
{
  struct queue *Q = (struct queue *)malloc(sizeof(struct queue));
  Q->size = capacity;
  Q->front = Q->rear = -1;
  Q->arr = (int *)malloc(capacity * (sizeof(int)));
  // printf("Queue done");
  return Q;
}

bool isempty(struct queue *Q)
{
  if (Q->front == Q->rear - 1)
  {
    return true;
  }
  return false;
}
bool isfull(struct queue *Q)
{
  if (Q->rear == Q->size - 1)
  {
    return true;
  }
}
void enqueue(struct queue *Q, int item)
{
  // printf("passed");
  if (isfull(Q) != true)
  {
    // printf("Passed2");
    if (Q->rear == -1)
    {
      Q->rear = 0;
      Q->front = 0;
    }
    else
    {
      // rintf("Pass");
      Q->rear++;
    }
    Q->arr[Q->rear] = item;
    // printf("Queue Overflow Error!");
    return;
  }
  printf("Queue Overflow Error!");
  return;
}
void dequeue(struct queue *Q)
{
  if (isempty(Q) == true)
  {
    Q->front++;
    return;
  }
  printf("Queue Underflow Error!");
  return;
}

void traverse(struct queue *Q)
{
  for (int i = Q->front; i <= Q->rear; i++)
  {
    printf("%d ", Q->arr[i]);
  }
}
int main()
{
  struct queue *Que = createqueue(10);
  dequeue(Que);
  traverse(Que);
}