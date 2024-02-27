#include <stdio.h>

int main()
{
  char input[100];
  printf("Welcome! Type a phrase to tokenize!\n");
  scanf("%99[^\n]", input);
  printf("\n",input);
  return 0;
}
