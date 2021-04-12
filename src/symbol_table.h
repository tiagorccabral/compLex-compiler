#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>

#include "uthash.h" /* https://troydhanson.github.io/uthash/userguide.html#_hash_operations */

enum symbolType {
  enumFunction = 'F',
  enumVariable = 'V',
  enumParameter = 'P' 
}; /* definition of enum */

typedef struct symbolNode {
  int symbolID; /* required key ID from documentation */
  char type;
  char *name;
  UT_hash_handle hh; /* makes this structure hashable */
} symbolNode;

symbolNode *symbolTable;

typedef struct symbolParam {
  int symbolID;
  int symbolType;
  char *name;
} symbolParam; /* used as a param on add_symbol_node function */

/* adds one entry (symbol node struct) to symbol table */
void add_symbol_node(symbolParam symbol);

void print_symbols();

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table();

#endif // SYMBOL_TABLE_