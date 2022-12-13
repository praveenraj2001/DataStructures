#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *current, *parent;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    if (head == NULL)
    {
        head = newnode;
        current = head;
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            parent = current;
            if ((newnode->data) < (current->data))
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        if ((newnode->data) > (parent->data))
            parent->right = newnode;
        else
            parent->left = newnode;
    }
}

void DeleteNoChild(int data)
{
    struct node *current = head, *parent;
    while (current != NULL)
    {
        if (data == (current->data))
        {
            if (current == parent->left)
                parent->left = NULL;
            else
                parent->right = NULL;
            free(current);
        }
        else if (data < (current->data))
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }
}

void Delete1Child(int data)
{
    struct node *current = head, *parent;
    while (current != NULL)
    {
        if (data == (current->data))
        {
            if (current == parent->left)
            {
                if (current->left != NULL)
                    parent->left = current->left;
                else if (current->right != NULL)
                    parent->left = current->right;
            }
            else
            {
                if (current->left != NULL)
                    parent->right = current->left;
                else if (current->right != NULL)
                    parent->right = current->right;
            }
            current = NULL;
            free(current);
        }
        else if (data < (current->data))
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }
}

struct node *findMax(struct node *subParent)
{
    struct node *temp = subParent->left, *nminone = subParent;
    int cnt = 0;
    while (temp->right)
    {
        if ((temp->right->right != NULL))
            temp = temp->right;
        else
            return temp;
    }
    return subParent;
}

void Delete2Child(int data)
{
    struct node *current = head, *parent, *temp;
    while (current != NULL)
    {
        if (data == (current->data))
        {
            {
                temp = findMax(current);
                if (current == temp)
                {
                    current->data = temp->left->data;
                    current->left = temp->left->left;
                    break;
                }
                else
                {
                    current->data = temp->right->data;
                    free(temp->right);
                    temp->right = NULL;
                    break;
                }
            }
        }
        else if (data < (current->data))
        {
            parent = current;
            current = current->left;
        }
        else
        {
            parent = current;
            current = current->right;
        }
    }
}

void InOrder(struct node *node)
{
    if (node == NULL)
        return;
    InOrder(node->left);
    printf("%d ", node->data);
    InOrder(node->right);
}

void PreOrder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    InOrder(node->left);
    InOrder(node->right);
}

void PostOrder(struct node *node)
{
    if (node == NULL)
        return;
    InOrder(node->left);
    InOrder(node->right);
    printf("%d ", node->data);
}

int main()
{
    insert(50);
    insert(60);
    insert(40);
    insert(55);
    insert(54);
    insert(56);
    insert(80);
    struct node *current = head;
    InOrder(current);
    cout << "\n";
    // DeleteNoChild(30);
    // Delete1Child(10);
    Delete2Child(60);
    InOrder(current);
    return 0;
}
