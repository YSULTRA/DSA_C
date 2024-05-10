#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    head = head->next;
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

struct Node *insertbegin(struct Node *head)
{
    struct Node *Temp;
    Temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element here:");
    scanf("%d", &Temp->data);
    Temp->next = head->next;
    head->next = Temp;
    return head;
}

struct Node *insertatlast(struct Node *head)
{
    struct Node *Temp, *original;
    Temp = (struct Node *)malloc(sizeof(struct Node));
    original = (struct Node *)malloc(sizeof(struct Node));
    original->data = head->data;
    original->next = head->next;
    while (head != NULL)
    {
        head = head->next;
    }
    printf("Enter the element:");
    scanf("%d\n", &Temp->data);
    head->next = Temp;
    Temp->next = NULL;
    return original;
}
int main()
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 90;
    head->next = second;
    second->next = NULL;
    print(head);
    head = insertbegin(head);
    head = insertbegin(head);
    print(head);
    head = insertatlast(head);
    print(head);
}