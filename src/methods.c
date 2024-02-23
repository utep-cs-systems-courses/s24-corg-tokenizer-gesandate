#include "tokenizer.h"
#include "stdio.h"
#include "stdlib.h"

int space_char(char c) {
  if (c == ' ' || c == '\t') {
    return 1;
  }
  return 0;
};

int non_space_char(char c) {
  if (c != ' ' || c != '\t'){
    return 1;
  }
  return 0;
    };


char *token_start(char *str) {
  char* npoint = (char*)malloc(sizeof(char));
  if (npoint == NULL){
    return npoint;
  }
  return npoint;
};

char *token_terminator(char *tokex) {
  //return token if not ' '
};

int count_tokens(char *str) {
  int count = 0;
  char* point = token_start(str);
  do{
    char* point = realloc(point, sizeof(char));
    count++;
  }while(point != NULL);
  printf("NULL POINTER");
    
  return count;
};

char *copy_str(char *inStr, short len) {};

char **tokenize(char* str) {};

void print_tokens(char **tokens) {};

void free_tokens(char **tokens) {};

int main(){
  char* str = "Hello World";
  printf("%d\n", count_tokens(str));
}
