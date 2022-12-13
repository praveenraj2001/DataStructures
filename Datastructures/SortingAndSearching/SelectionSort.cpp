#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selctionSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    { // Here i acts as sorted till flag
        for (int j = (i + 1); j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr[j], arr[i]);
            }
        }
    }
}
int main()
{
    int k[] = {1, 5, 8, 9, 6, 7, 4, 3, 2, 0};
    selctionSort(k, 10);
    for (int i = 0; i < 10; i++)
        cout << k[i] << " ";

    return 0;
}
