#include <iostream>
#define capacity 5
using namespace std;
int front = 0, rear = 0; // Deletion from front, Insertion from rear
int queue[capacity];

void Traverse()
{
    if (front == rear)
        printf("queue is empty\n");
    else
    {
        int k = 0;
        while (k <= rear - 1)
        {
            printf("%d ", queue[k]);
            k++;
        }
    }
}
void insert()
{
    if (rear == (capacity - 1))
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter the element to be inserted\n");
        scanf("%d", &queue[rear++]);
    }
}
void deletei()
{
    if (front == rear)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("\n%d deleted\n", queue[front]);
        for (int i = 1; i < rear; i++)
        {
            queue[i - 1] = queue[i];
        }
        rear--;
    }
}

int main()
{
    insert();
    insert();
    insert();
    Traverse();
    deletei();
    Traverse();

    return 0;
}