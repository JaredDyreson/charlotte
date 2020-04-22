#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "charlotte.h"
#define NUMBER_OF_STRINGS 120
#define MAX_STRING_SIZE 1000


split_string* split_string_constructor(){
  split_string* s = malloc(sizeof(split_string));
  s->contents = malloc(NUMBER_OF_STRINGS * sizeof(char*));
  s->size = 0;
  return s;
}

void split_string_destructor(split_string* sp){
  for(int i = 0; i < NUMBER_OF_STRINGS; ++i){
    free(sp->contents[i]);
  }
  free(sp->contents);
}

char* strip(char* string){
  if(string == NULL){ return string; }
  while(*string != '\0' && isspace(*string) && !isalpha(*string)){*string++;}
  return string;
}

split_string* split(char* string, const char* pattern){
  split_string* sp = split_string_constructor();

  char* mutate = strdup(string);
  char* token = strtok(mutate, pattern);
  size_t i = 0;
  while(token != NULL){
    sp->contents[i] = malloc((MAX_STRING_SIZE+1) * sizeof(char));
    strcat(sp->contents[i++], strip(token));
    token = strtok(NULL, pattern);
  }
  sp->size = i;
  return sp;
}

void strip_test(char* string){
  /*strip_test("   Test");*/
  char* stripped = strip(string);
  assert(isalpha(stripped[0]));
  printf("value of stripped is: %s\n", stripped);
  printf("ALL ASSERTIONS PASSED\n");
}

void split_test(const char* content, const char* delim){
  split_string* s = split(content, delim);
  for(size_t i = 0; i < s->size; ++i){
    printf("%s\n", s->contents[i]);
  }
  split_string_destructor(s);
}
int main(){
  split_test("Hello World", " ");
  /*char** split_string = ("Hello World", " ");*/
  /*printf("value of i: %d\n", i);*/
  /*for(int j = 0; j < i; ++j){*/
    /*printf("%s\n", split_string[j]);*/
  /*}*/
  return 0;
}
