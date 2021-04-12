#include "symbol_table.h"

symbolNode *symbolTable = NULL;

void add_symbol_node(symbolParam symbol) {
  struct symbolNode *symbolPointer;
  char sType = symbol.symbolType;
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(symbolTable, &symbol.symbolID, symbolPointer);
  if (symbolPointer == NULL) {
    symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
    symbolPointer -> symbolID = symbol.symbolID;
    symbolPointer -> type = sType;
    symbolPointer -> name = symbol.name;
    HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
  } else {
    printf("symbol %s already declared!\n", symbol.name);
  }
}

void print_symbols() {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;

  printf("\n================== Symbols table ==================\n\n");
  printf("Symbol ID     Symbol Name              Symbol Type\n\n");
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    printf("   %-5d\t %-15s\t %5c\n", s -> symbolID, s -> name, s -> type);
  }
  printf("===================================================\n");
}

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table(){
  symbolNode *s, *tmp;
  HASH_ITER(hh, symbolTable, s, tmp) {
    HASH_DEL(symbolTable, s);
    free(s);
  }
}