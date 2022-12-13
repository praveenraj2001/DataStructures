#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int lb, int mid, int ub)
{
    int i, j, k;
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[lb + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = lb;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergearray(int arr[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergearray(arr, lb, mid);
        mergearray(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = {0, 1, 0, 1, 2, 4};
    int left, right, mid;
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    mergearray(arr, 0, arrsize - 1);
    printArray(arr, arrsize);
    return 0;
}
