#include <stdio.h>

int main()
{
    int n;
    printf("Enter the Size of the Array:");
    scanf("%d", &n);
    int arr[n];
    int temp;
    for (int i = 0; i < n; i++)
    {
        printf("Enter Element No %d :", i);
        scanf("%d", &temp);
        arr[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}