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

symbolNode *symbolTable = NULL;

typedef struct symbolParam {
  int symbolID;
  int symbolType;
  char *name;
} symbolParam;

/* adds one entry (symbol node struct) to symbol table */
void add_symbol_node(symbolParam symbol) {
  printf("ENTROU %d\n", symbol.symbolID);
  printf("ENTROU %s\n", symbol.name);
  struct symbolNode *symbolPointer;
  char sType = symbol.symbolType;
  printf("ENTROU ENUM %c\n", sType);
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(symbolTable, &symbol.symbolID, symbolPointer);
  if (symbolPointer == NULL) {
    symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
    symbolPointer -> symbolID = symbol.symbolID;
    symbolPointer -> type = sType;
    symbolPointer -> name = symbol.name;
    HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
  } else {
    printf("inserido symbolID: %d\n", symbol.symbolID);
  }
}

void print_symbols() {
  symbolNode *s;

  printf("\n============== Symbols table ==============\n\n");
  printf("Symbol ID     Symbol Name              Symbol Type\n\n");
  for (s = symbolTable; s != NULL; s = s -> hh.next) {
    printf("   %-5d\t %-15s\t %5c\n", s -> symbolID, s -> name, s -> type);
  }
  printf("===========================================\n");
}