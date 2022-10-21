#include<stdio.h>
#include<stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c) {
  if (c == ' ' || c == '\t'){
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  if (c == '\0' || c == ' ' || c == '\t'){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str){
  int i = 0;
  while (space_char(*(str + i))){
    i++;
  }
  if (*(str + i) == '\0'){
    return 0;
  }
  return (str + i);
} 

/* Returns a pointer terminator char following *word */
// Did not use
char *word_terminator(char *word){
  int i = 0;
  while(non_space_char(*(word + i))){
    i++;
  }
  return (word + i);
}
//NOT NEEDED
int letter_count(char *str){
  int count = 0;
  while(non_space_char(*(str + count)) && *(str + count) != '\0'){
    count++;
  }
  return count;
}
//Used in cpy string for our add history
int total_length(char *str){
  int i = 0;
  while(*(str + i) != '\0'){
    i++;
  }
  return i;
}

/* Counts the number of words in the string argument. */
int count_words(char *str){
  if (*str == '\0'){
    return 0;
  }
  int count = 0;
  char* new_ptr = str;
  while (word_start(new_ptr) != 0){
    new_ptr = word_start(new_ptr);
    new_ptr = word_terminator(new_ptr);
    count++;
  }
  return count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char* word = (char*)malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len || *(inStr + i) !='\0'; i++){
    word[i] = *(inStr + i);
  }
  word[len] = '\0';
  return word;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  
  int num_words = count_words(str);
  char** array = (char**)malloc(sizeof(char*) * num_words); // +1?
  int word_length;
  char *ptr = word_start(str);
  int i = 0;
  //Using letter_counting HERE
  for (i = 0; i < num_words; i++){
    word_length = word_terminator(ptr) - word_start(ptr);
    //    array[i] = (char*)malloc(sizeof(char)*letters);
    array[i] = copy_str(ptr, word_length);
    ptr = word_terminator(ptr);
    ptr = word_start(ptr);
  }
  // array[i] = (char*)malloc(sizeof(char)*1);
  //array[i] = "0"; //OR \0 ???
  return array;
}

/* Prints all tokens. */
void print_tokens(char **tokens){
  int i = 0;
  for (i = 0; tokens[i] != NULL; i++){
    printf("token[%d]: %s\n", i, tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  int i;
  for (i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}

