#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char input[100];
  printf("Welcome! Type a phrase to tokenize!\n");
  scanf("%99[^\n]", input);
  //printf("%s\n", input);
  char *str = input;
  char **tokens = tokenize(str);
  print_tokens(tokens);
  //free_tokens(arr);
}
