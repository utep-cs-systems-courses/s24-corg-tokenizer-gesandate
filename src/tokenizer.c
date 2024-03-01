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

char *token_terminator(char *str) {
  //return token if not ' '
  while (*str != ' ' && *str != '\0'){
    str++;
  }
  return str;
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

char *copy_str(char *inStr, short len) {
  char* nBlock = (char *)malloc((len + 1)* sizeof(char));
  if (nBlock == NULL){
    return NULL;
  }
  for (int i = 0; i < len && inStr[i] != '\0'; i++){
    nBlock[i] = inStr[i];
  }

  nBlock[len] = '\0';

  return nBlock;
};

char **tokenize(char* str) {
  int amount = count_tokens(str);
  char **ptrarr = (char**)malloc(100 * sizeof(char*));
  char  *ptr    = token_start(str);

  if (ptrarr == NULL){
    return NULL;
  }

  char *start, *end;
  int tIdx;
  
  while (*str != '\0'){
    start = token_start(str);
    if (start == NULL){
      //printf("%s\n","Check 1");
      break;
    }
    end = token_terminator(start);

    int tokLen = end - start;
    ptrarr[tIdx] = copy_str(start, tokLen);
    //printf("%s\n","Check 2");
    if (ptrarr[tIdx] == "\0"){
      
      for(int i = 0; i < tIdx; i++) {
	free(ptrarr[i]);
      }
      free(ptrarr);
      //printf("%s\n","Check 3");
      return NULL;
    }
    //printf("%s\n",ptrarr[tIdx]);
    tIdx++;
    str = end;
  }
  //printf("%s\n","Check 4");
  return ptrarr;
};

void print_tokens(char **tokens) {
  for (int i = 0; *tokens[i] != '\0'; i++){
    printf("%s\n", tokens[i]);
  }
};

void free_tokens(char **tokens) {};

int main(){
  char* str = "Hello World Twenty Seventy Seven";
  printf("%d\n", count_tokens(str));

  print_tokens(tokenize(str));
}
