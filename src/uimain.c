#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include"tokenizer.h"
#include "history.h"

int main() {  
  List *list1 = init_history();

  while(1) {
    char str[100];
    printf("IN >");
    fgets(str, 100, stdin);

    if (str[0] == '^'){
      break;
    }
    else if(str[0] == '!'){
      if(isdigit(str[1])){
	int index = atoi(&str[1]);
	char *get_str = get_history(list1, index);
	char **words = tokenize(get_str);
	print_tokens(words);
	free_tokens(words);
      }
      else if(str[1] == 'h'){
	print_history(list1);
      }
      else{
	continue;
      }
    }
    else{
      printf("OUT > ADDED: %s", str);
    }
    add_history(list1, str);
  }
  
  return 0;
}
