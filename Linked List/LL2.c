#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *pointer)
{
    while (pointer != NULL)
    {
        printf("%d ", pointer->data);
        pointer = pointer->next;
    }
}

void insertatbeg(struct Node *point)
{
    int ele;
    int temp = point->data;
    struct Node *temp1 = point->next;
    printf("Enter the element:");
    scanf("%d", &ele);
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node *));
    point->data = ele;
    point->next = new;
    new->data = temp;
    new->next = temp1;
}
void insertatindex(struct Node *head, int index)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node *));
    struct Node *pointer = head;
    printf("Enter the new element:");
    int ele;
    scanf("%d", ele);
    new->data = ele;
    int i = 0;
    while (i != index - 1)
    {
        pointer = pointer->next;
        i++;
    }
    new->next = pointer->next;
    pointer->next = new;
    return;
}
int main()
{
    struct Node *head, *first, *second;
    head = (struct Node *)malloc(sizeof(struct Node *));
    first = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 5;
    second->next = NULL;

    print(head);

    printf("//\n");

    insertatbeg(head);

    printf("//\n");

    print(head);

    printf("//\n");

    insertatbeg(head);

    printf("//\n");

    print(head);

    printf("//\n");
    insertatindex(head, 2);
    printf("//\n");

    print(head);
}