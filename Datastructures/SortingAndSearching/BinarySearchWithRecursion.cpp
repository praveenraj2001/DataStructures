#include <iostream>
using namespace std;
#define searchElement 7
char *binarySearch(int arr[], int size, int element, int min, int max)
{
    int mid = (min + max) / 2;

    if (arr[mid] == element)
        return "Found";

    else if (element > arr[mid])
        return binarySearch(arr, size, searchElement, mid, max);

    else if (element < arr[mid])
        return binarySearch(arr, size, searchElement, min, mid);

    else
        return "Not Found";
}
int main()
{
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int min = 0;
    int max = (sizeof(array) / 4 - 1);
    cout << binarySearch(array, sizeof(array) / 4, searchElement, min, max);

    return 0;
}
