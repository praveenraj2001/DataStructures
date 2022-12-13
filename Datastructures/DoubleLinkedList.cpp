#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *head = NULL;
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
        cout << "front\n";
        while (temp->right != NULL)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << temp->data << " ";
        cout << "\nback\n";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
    }
}
void append(int data)
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->right != NULL)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
    }
}
void insertAT(int data, int pos)
{
    struct node *temp1 = head, *temp2;
    struct node *newnode = (struct node *)malloc(sizeof(struct node *));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (pos == 1)
    {
        newnode->left = NULL;
        newnode->right = temp1;
        temp1->left = newnode;
        head = newnode;
    }
    else
    {
        pos--;
        while (--pos)
        {
            temp1 = temp1->right;
        }
        temp2 = temp1->right;
        newnode->right = temp2;
        temp2->left = newnode;
        newnode->left = temp1;
        temp1->right = newnode;
    }
}
void deleteAT(int pos)
{
    struct node *temp1 = head, *temp2;
    if (pos == 1)
    {
        head = head->right;
        head->left = NULL;
        temp1->right = NULL;
        free(temp1);
    }
    else
    {
        pos--;
        while (--pos)
        {
            temp1 = temp1->right;
        }
        temp2 = temp1->right;
        temp1->right = temp2->right;
        temp2->right->left = temp1;
        temp2->right = NULL;
        temp2->left = NULL;
        free(temp2);
    }
}

void reverse()
{
    struct node *temp1 = head, *temp2, *temp3;
    while (temp1 != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->right;
        temp3 = temp2->left;
        temp2->left = temp2->right;
        temp2->right = temp3;
    }
    head = temp2;
}
int main()
{
    traverse();
    append(10);
    append(20);
    append(30);
    append(40);
    traverse();
    cout << "******\n";
    deleteAT(2);
    traverse();
    cout << "******\n";
    insertAT(20, 2);
    traverse();
    cout << "******\n";
    reverse();
    traverse();
    return 0;
}
