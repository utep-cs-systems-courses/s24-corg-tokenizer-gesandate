#include "tokenizer.h"
#include "stdio.h"

int main() {
  
}
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
  char *ptr = malloc(sizeof(char));
  if (ptr == NULL) {
    return 0;
  }
};

char *token_terminator(char *tokex) {};

int count_tokens(char *str) {};

char *copy_str(char *inStr, short len) {};

char **tokenize(char* str) {};

void print_tokens(char **tokens) {};

void free_tokens(char **tokens) {};
