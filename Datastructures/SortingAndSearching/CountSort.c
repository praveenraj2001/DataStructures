#include <stdio.h>

int main()
{
    int arr[] = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9}, temp, j, k = 10;

    int n = sizeof(arr) / sizeof(arr[0]);
    int count[10];
    int b[n];
    for (int i = 0; i < n; i++)
    {
        ++count[arr[i]];
    }
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        b[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", b[i]);
    }
}
