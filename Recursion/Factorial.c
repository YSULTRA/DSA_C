#include <stdio.h>

int factorial(int n) // factorial function header
{
    if (n == 1) // base case
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1); // recursive call
    }
}

int main()
{
    int n;
    printf("Enter  Number Here:"); // number to find factorial
    scanf("%d", &n);
    int ans;
    ans = factorial(n);
    printf("The Factorial of %d is : %d", n, ans); // ans
}