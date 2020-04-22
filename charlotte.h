// Written by Jared Dyreson CSUF 2021
// All rights reserved
//

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct split_string split_string;

struct split_string{
  char** contents;
  size_t size;
};

// constructors and destructors

split_string* split_string_constructor();
void split_string_destructor(split_string*);

// Python inspired string functions

char* strip(char*);
split_string* split(char*, const char*);


// Tests
//
void strip_test(char*);
