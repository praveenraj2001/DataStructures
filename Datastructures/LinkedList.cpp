#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;
void append(int);
void traverse();
void deleteAT(int);
void insertAT(int, int);
void reverse();

int main()
{
    traverse();
    append(10);
    append(20);
    append(30);
    append(40);
    traverse();

    deleteAT(2);
    traverse();

    insertAT(20, 2);
    traverse();

    reverse();
    traverse();
    return 0;
}

void traverse()
{
    struct node *temp;
    if (head == NULL)
    {
        cout << "List is empty\n";
    }
    else
    {
        temp = head;
        cout << "\nLinked list --";
        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << " ";
    }
}
void append(int data)
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->link = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
}
void insertAT(int data, int pos)
{
    struct node *temp1 = head, *temp2;
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->link = NULL;

    if (pos == 1)
    {
        newnode->link = temp1;
        head = newnode;
    }
    else
    {
        pos--;
        while (--pos)
        {
            temp1 = temp1->link;
        }
        temp2 = temp1->link;
        newnode->link = temp2;
        temp1->link = newnode;
    }
}
void deleteAT(int pos)
{
    struct node *temp1 = head, *temp2;
    if (pos == 1)
    {
        head = head->link;
        temp1->link = NULL;
        free(temp1);
    }
    else
    {
        pos--;
        while (--pos)
        {
            temp1 = temp1->link;
        }
        temp2 = temp1->link;
        temp1->link = temp2->link;
        temp2->link = NULL;
        free(temp2);
    }
}

void reverse()
{
    struct node *current = head, *next = head, *previous = NULL;
    while (current != NULL)
    {
        next = next->link;
        current->link = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
