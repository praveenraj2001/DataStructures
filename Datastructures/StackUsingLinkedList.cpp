#include <iostream>
using namespace std;
// Stack using linked list
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;

void push(int);
void pop();
void traverse();

void push(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->link = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->link = head;
        head = newnode;
    }
}

void pop()
{
    struct node *temp1 = head;
    head = temp1->link;
    free(temp1);
}

void traverse()
{
    struct node *temp;
    if (head == NULL)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        temp = head;
        cout << "\nStack Elements --";
        while (temp->link != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << temp->data << " ";
    }
}

int main()
{
    traverse();
    push(10);
    push(20);
    push(30);
    push(40);
    traverse();
    pop();
    traverse();

    push(40);
    traverse();

    return 0;
}
