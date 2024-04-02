#include "stdio.h"
#include "history.h"
#include "tokenizer.h"
#include "stdlib.h"

List* init_history(){
  List* ptr = (List*)malloc(sizeof(List));
  ptr->root= NULL;
  return ptr;
}

void add_history(List *list, char *str){
  //looking for space to place the items
  Item *head = list->root;
  Item *arr  = (Item*)malloc(sizeof(Item));
  int id = 0;
  //checks if the list is empty
  //if its empty make it the root, else make it the .next
  arr->str = str;
  if (list->root == NULL){
    list->root = arr;
    arr->next = NULL;
    arr->id = id;
  }
  else{
    id++;

    while(head->next != NULL){
      head = head->next;
      id++;
    }//
    arr->next = NULL;
    arr->id = id;
    head->next = arr;
  }
}

char *get_history(List *list, int id){
  //dafodils
  Item *curr = list->root;
  while (curr->id < id){
    curr = curr->next;
  }
  return curr->str;
}

void print_history(List *list){
  Item *curr = list->root;
  /*
  for (int i = 0; curr->next != NULL; i++){
    printf("%c", get_history(list, i));
  }
  */
  //free_history(list);
  int i = 0;
  while (curr != NULL){
    printf("%c", get_history(list,i));
    if (curr->next != NULL){
      curr = curr->next;
      i++;
    }
  }
}

void free_history(List *list){
  Item *curr = list->root;
  while (curr != NULL){
    Item *temp = curr;
    if (curr->next != NULL){
      curr = curr->next;
    }
    free(temp->str);
    free(temp);
  }
  free(list);
}

//int main(){}
