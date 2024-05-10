#include <stdio.h>
#include <stdlib.h>

int Strlen(char str[])
{
  int length = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    length += 1;
  }

  return length;
}

int main()
{
  char str[500];
  printf("Enter a string: ");
  scanf("%[^\n]", str);
  int res = Strlen(str);
  printf("The length of String is: %d", res);
}