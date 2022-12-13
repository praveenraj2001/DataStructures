#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}
int main()
{
    int k[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    bubbleSort(k, 10);
    for (int i = 0; i < 10; i++)
        cout << k[i] << " ";

    return 0;
}
