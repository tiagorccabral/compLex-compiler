#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdio.h>
#include <stdlib.h>

#include "uthash.h" /* https://troydhanson.github.io/uthash/userguide.html#_hash_operations */
#include "utlist.h"
#include "utarray.h"

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
  UT_hash_handle hh; /* makes this structure hashable */
} symbolNode;

symbolNode *symbolTable;

typedef struct symbolParam {
  int symbolID;
  int symbolType; /* could be F, V, P */
  char *type; /* type of the ID (int, float, set, etc) */
  char *name;
} symbolParam; /* used as a param on add_symbol_node function */

typedef struct scopeStack {
  int level;
  char *name;
  struct scopeStack *next;
} scopeStack; /* element of each scope */

scopeStack *scopeStackHead; /* pointer to beginning of scope el stack */

void intchar_copy(void *_dst, const void *_src);
void intchar_dtor(void *_elt);

UT_array *scopeList;

UT_icd intchar_icd;

/* adds one entry (symbol node struct) to symbol table */
void add_symbol_node(symbolParam symbol);

void print_symbols();

/* add one list element to scopes list */
void create_new_scope();

/* print scope list */
void print_scopes_list();

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table();

#endif // SYMBOL_TABLE_