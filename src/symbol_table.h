#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>

#include "uthash.h" /* https://troydhanson.github.io/uthash/userguide.html#_hash_operations */
#include "utstack.h"

enum symbolType {
  enumFunction = 'F',
  enumVariable = 'V',
  enumParameter = 'P' 
}; /* definition of enum */

typedef struct symbolNode {
  int symbolID; /* required key ID from documentation */
  char symbolType; /* could be F, V, P */
  char *type; /* type of the ID (int, float, set, etc) */
  char *name;
  int scope; /* scope of symbol */
  int scopeID; /* unique ID of scope */
  UT_hash_handle hh; /* makes this structure hashable */
} symbolNode;

symbolNode *symbolTable;

typedef struct symbolParam {
  int symbolID;
  int symbolType; /* could be F, V, P */
  char *type; /* type of the ID (int, float, set, etc) */
  char *name;
  int scope; /* scope of symbol */
  int scopeID; /* unique ID of scope */
} symbolParam; /* used as a param on add_symbol_node function */

typedef struct scopeStack {
  int level; /* numeric representation of scope level */
  int scopeID; /* unique ID of scope */
  struct scopeStack *next;
} scopeStack; /* element of each scope */

typedef struct scopeInfo {
  int level; /* numeric representation of scope level */
  int scopeID; /* unique ID of scope */
}scopeInfo;

scopeStack *scopeStackHead; /* pointer to beginning of scope el stack */

/* adds one entry (symbol node struct) to symbol table */
void add_symbol_node(symbolParam symbol);

void print_symbols();

/* add one level to current scope counting */
void create_new_scope_level();

/* removes one level of scope stack */
void decrease_scope_level();

/* releases allocated memory for scopes stack */
void free_scope_stack();

/* returns the scope stack head, that is the current scope */
scopeInfo get_current_scope();

/* generates random 5 digit number to be used as unique ID for scope */
int gen_random_uniqueID();

/* print scope list */
void print_scopes_list();

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table();

#endif // SYMBOL_TABLE_