#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createnode(int value)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->left = newnode->right = NULL;
  return newnode;
}

void insert(struct node *root, int key)
{
  if (root == NULL)
  {
    root = createnode(key);
  }
}

int main() {}