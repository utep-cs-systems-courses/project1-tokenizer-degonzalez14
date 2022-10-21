#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

typedef struct S_Item{
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List{
  struct s_Item *root;
} List;

List* init_history(){
  //Initialize memory for list and initial node
  List *head = malloc(sizeof(List));
  Item *node = malloc(sizeof(Item));
  //Initialize node
  node -> next = NULL;
  node -> id = 0;
  //Initialize head(root)
  head -> root = node;
  return head;
}

//Edit this to add at the end of the list
void add_history(List *list, char *str){
  //Initializing memory for node to be added
  Item *node = malloc(sizeof(Item));
  //Copying given string into created node
  node -> str = copy_str(str, total_length(str));
  //Creating a pointer to root node(head)
  Item *currNode = list -> root;
  //Setting id as 1 more than head id -> specific to this design
  node -> id = (currNode -> id) + 1;
  //Setting next pointer to head
  node -> next = list -> root;
  //Updating head pointer to be the newly created node
  list -> root = node;
}

char *get_history(List *list, int id){
  Item *currNode = list -> root;
  //traversing llist 
  while (currNode -> id != id && currNode -> next != NULL){
    currNode = currNode -> next;
  }
  //printf("[%d]: %s\n", currNode -> id, currNode -> str);
  return currNode -> str;
}

void print_history(List *list){
  Item *currNode = list -> root;

  while (currNode -> next != NULL){
    printf("[%d]: %s", currNode -> id, currNode -> str);
    currNode = currNode -> next;
  }
}
