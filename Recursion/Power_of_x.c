#include <stdio.h>

int power(int x, int n)
{
    int pow;
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        pow = power(x, n / 2);
        return pow * pow;
    }
    else
    {
        pow = power(x, (n - 1) / 2);
        return x * pow * pow;
    }
    return pow;
}

int main()
{
    int x;
    printf("Enter  Number Here:");
    scanf("%d", &x);
    int n;
    printf("Enter Power to Calculate:");
    scanf("%d", &n);
    int result = power(x, n);
    printf("The Ans is : %d", result);
}