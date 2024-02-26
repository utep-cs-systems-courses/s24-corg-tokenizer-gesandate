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
  while (*str != '\n' && *str == ' '){
    str++;
  }

  if (*str == '\0') {
    return NULL;
  }

  return str;
};

char *token_terminator(char *tokex) {
  //return token if not ' '
};

int count_tokens(char *str) {
  if (str == NULL){
    return 0;
  }
  int count = 0;
  char* point = token_start(str);
  while (*point != '\n'){
    while (*point == ' '){
      point++;
    }
  
    if (*point == '\n'){
      break;
    }
    count++;

    while (*point != ' ' && *point != '\n'){
      point++;
    }
  }
    
  return count;
}

char *copy_str(char *inStr, short len) {};

char **tokenize(char* str) {};

void print_tokens(char **tokens) {};

void free_tokens(char **tokens) {};

int main(){
  char* str = "Hello World Twenty Seventy Seven";
  printf("%d\n", count_tokens(str));
}
