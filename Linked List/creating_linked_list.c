#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int data;
    struct node *next;
} *head = NULL;

void insertatbegin(int value)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void traversal()
{
    struct node *temp2 = head;
    while (temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
}

void insertatend(int value)
{
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    struct node *new = malloc(sizeof(struct node));
    new->data = value;
    new->next = NULL;
    temp->next = new;
}

void insertatindex(int value, int index)
{
    struct node *temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefrombegin()
{
    struct node *temp = head;
    head = temp->next;
    free(temp);
}
void deletefromend()
{
    struct node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}
void deleteatindex(int index)
{
    int i = 0;
    struct node *temp = head;
    struct node *temp2 = head->next;
    while (i != index - 1)
    {
        temp = temp->next;
        temp2 = temp2->next;
        i++;
    }
    temp->next = temp2->next;
    free(temp2);
}
int main()
{
    while (true)
    {
        printf("\n1.Insert at the front\n"
               "2.Insert at the End\n"
               "3.Insert at particular Index\n"
               "4.Delete from Front\n"
               "5.Delete from End\n"
               "6.Delete from Particular Index\n"
               "7.Print the Linked List\n"
               "8.Exit\n");
        int x;
        printf("Enter Choice Here:");
        scanf("%d", &x);
        if (x == 1)
        {
            int value;
            printf("enter the value here:");
            scanf("%d", &value);
            insertatbegin(value);
        }
        else if (x == 2)
        {
            int value;
            printf("enter the value here:");
            scanf("%d", &value);
            insertatend(value);
        }
        else if (x == 3)
        {
            int value;
            printf("enter the value here:");
            scanf("%d", &value);
            int index;
            printf("enter the index here:");
            scanf("%d", &index);
            insertatindex(value, index);
        }
        else if (x == 4)
        {
            deletefrombegin();
            printf("Value deleted\n");
        }
        else if (x == 5)
        {
            deletefromend();
            printf("Value deleted\n");
        }
        else if (x == 6)
        {
            int index;
            printf("Enter the index:");
            scanf("%d", &index);
            deleteatindex(index);
        }
        else if (x == 7)
        {
            traversal();
        }
        else
        {
            break;
        }
    }
    return 0;
}