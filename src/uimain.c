#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char input[100];
  
  List *history = init_history();
  char **tokens;
  
 tokenize:
  printf("Welcome! Type a phrase to tokenize!\n");
  scanf("%99[^\n]", input);
  //printf("%s\n", input);
  char *str = input;
  //List *history = init_history();
  add_history(history, str);
  tokens = tokenize(str);

 print_tokens:
  print_tokens(tokens);
  //free_tokens(tokens);
  //free_history(history);
  
 options:
  printf("Type 'H' to view history, 'P' to print tokens again,'Q' to quit, or 'T' to tokenize another phrase!\n");
  char input2;
  scanf(" %c", &input2);
  switch( input2 ){
  case 'Q':
    goto end;
    break;
    
  case 'T':
    goto tokenize;
    break;
  
  case 'H':
    print_history(history);
    goto end;
    break;

  case 'P':
    goto print_tokens;
    break;
    
  default:
    printf("Unrecognized option, please try again!");
    goto options;
    break;
    
 }
 end:
  free_tokens(tokens);
  free_history(history);
  return 0;
}
