#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printlinkedlist(struct Node *pointer) // print the linked list
{
    int i = 1;
    while (pointer != NULL)
    {
        printf("Element%d: %d\n", i, pointer->data);
        pointer = pointer->next;
        i += 1;
    }
}

void addelement(struct Node *new_node)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_node->next = NULL;
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    printf("Enter the next data: ");
    scanf("%d", &new_node->next->data);
    new_node->next = new_node->next->next;
    printf("\n");
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    /*allocate memory for nodes in the linked list in heap*/

    // link the head to the second
    head->data = 1;
    head->next = second;

    // link the second to the third
    second->data = 58;
    second->next = third;

    // link the third to the NULL
    third->data = 3;
    third->next = NULL;

    printlinkedlist(head);
    return 0;
}