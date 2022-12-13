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
        cout << "Circular List is empty\n";
    }
    else
    {
        temp = head;
        cout << "\nCircular List --> ";
        while (temp->right != head)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << temp->data << " ";
        cout << temp->right->data << " ";
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
        head->right = head;
        head->left = head;
    }
    else
    {
        temp = head;
        while (temp->right != head)
        {
            temp = temp->right;
        }
        temp->right = newnode;
        newnode->left = temp;
        newnode->right = head;
        head->left = newnode;
    }
}
void deleteAT(int pos)
{
    struct node *temp1 = head, *temp2;
    if (pos == 1)
    {
        head = temp1->right;
        temp1->left->right = temp1->right;
        temp1->right->left = temp1->left;
        free(temp1);
    }
    else
    {
        while (--pos)
        {
            temp1 = temp1->right;
        }
        temp1->left->right = temp1->right;
        temp1->right->left = temp1->left;
        free(temp1);
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
        newnode->left = temp1->left;
        newnode->right = temp1;
        temp1->left->right = newnode;
        temp1->left = newnode;
        head = newnode;
    }
    else
    {
        while (--pos)
        {
            temp1 = temp1->right;
        }
        newnode->left = temp1->left;
        newnode->right = temp1;
        temp1->left->right = newnode;
        temp1->left = newnode;
    }
}
void reverse()
{
}
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
    return 0;
}
