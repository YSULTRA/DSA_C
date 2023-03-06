#include <stdio.h>

int binarysearch(int arr[], int ele, int size)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high)
    { // use <= instead of < to handle all cases
        mid = (low + high) / 2;

        if (arr[mid] == ele)
        {
            return 1;
        }
        else if (arr[mid] < ele)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ans = binarysearch(arr, 4, 10);
    printf("%d", ans);
}