#include <stdio.h>
#include <stdlib.h>

int countOddElements(int arr[][3])
{
  int OddCounter = 0;
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] % 2 != 0)
      {
        ++OddCounter;
      }
    }
  }
  return OddCounter;
}

void changeLastElementToZero(int arr[][3])
{
  for (int i = 0; i < 2; i++)
  {
    arr[i][2] = 0;
  }
}

void printMultiDimArray(int arr[][3])
{
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  int arr[2][3];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("Enter the value of %d,%d: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }
  printMultiDimArray(arr);
  printf("The number of Odd Elements are: %d\n", countOddElements(arr));
  changeLastElementToZero(arr);
  printMultiDimArray(arr);
  printf("Last Elements changed to Zero");
}