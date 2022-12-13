#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 // THIS IS A MACRO(A CONSTANT)
                   // we define macro using pre-processor directives
// Pre-processing happens before compilation
int stack[CAPACITY];
int top = -1; // because top location is not pointing to any index at start

int isFull()
{ // check if full or not
    if (top == CAPACITY - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{ // check if empty or not
    if (top == (-1))
    {
        return 1;
    }
    return 0;
}

void Push()
{ // insert an element
    if (isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        int element;
        printf("enter the element\n");
        scanf("%d", &element);
        top++;
        stack[top] = element;
        printf("%d inserted\n", element);
    }
}

int Pop()
{ // remove an element and return it
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        printf("popped -- %d\n", stack[top]);
        top--;
    }
}

int Peek()
{ // do not remove just display the top element
    if (isEmpty())
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        return stack[top];
    }
}

void Traverse()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("****\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

        printf("Please enter your choice\n");
        scanf("%d", &choice);
        printf("****\n");

        switch (choice)
        {
        case 1:
            Push();
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Traverse();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid input \n\n");
            break;
        }
    }
}
