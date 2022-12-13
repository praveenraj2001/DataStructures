#include <iostream>
using namespace std;
char *binarySearch(int arr[], int size, int element)
{
    int min = 0, max = (size - 1), mid = 0;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (arr[mid] == element)
        {
            return "Found";
        }
        else if (element > arr[mid])
            min = mid;
        else if (element > arr[mid])
            max = mid;
        else
            return "Not Found";
    }
}
int main()
{
    int array[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << binarySearch(array, sizeof(array) / 4, 2);

    return 0;
}
