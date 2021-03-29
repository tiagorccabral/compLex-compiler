#include <stdio.h>
#include <stdlib.h>

/* struct to represent the AST and nodes */
typedef struct parserNode {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  char* value;
  char* type;
} parserNode;

parserNode* parser_ast = NULL;

parserNode* add_new_node() {
  parserNode *node = (parserNode *)calloc(1, sizeof(parserNode));
  return node;
}