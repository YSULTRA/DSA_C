#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *Insert(node *head)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    printf("Enter the value of element here:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newnode;
    }
    return head;
}

void Print(node *head)
{
    node *current;
    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    free(current);
}

node *InsertInBetween(node *head, int index)
{
    node *current;
    current = (node *)malloc(sizeof(node));
    current = head;
    int i = 0;
    while (i != index - 1)
    {
        current = current->next;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->next = current->next;
    current->next = newnode;
    printf("Enter the value here:");
    scanf("%d", &newnode->data);
    return head;
}

node *InsertAtEnd(node *head)
{
    node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
}

int main()
{
    node *head = NULL;
    head = Insert(head);
    head = Insert(head);
    Print(head);
    head = InsertInBetween(head, 1);
    Print(head);
    return 0;
}