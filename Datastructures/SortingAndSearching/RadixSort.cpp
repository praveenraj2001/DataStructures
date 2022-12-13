#include <stdio.h>

int countsort(int arr[], int n, int pos)
{
    int count[10] = {0}, k = 10;
    int b[10];
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int i = 1; i < k; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        b[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

int main()
{
    int arr[] = {432, 8, 530, 90, 88, 231, 11, 45, 677, 199}, temp, j, max;
    int pos;
    int n = sizeof(arr) / sizeof(arr[0]);
    max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])

            max = arr[i];
    }
    // printf("%d",max);
    for (pos = 1; max / pos > 0; pos *= 10)
    {
        countsort(arr, n, pos);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
