#include <iostream>

using namespace std;
char *linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == arr[i])
            return "Found";
    }
    return "Not Found";
}

int main()
{
    int array[] = {3, 4, 5, 2, 4, 6, 7, 4, 1, 134, 6, 8, 8654};
    cout << linearSearch(array, sizeof(array) / 4, 1);

    return 0;
}
