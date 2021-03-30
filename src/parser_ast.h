#include <stdio.h>
#include <stdlib.h>

enum astNodeType {
  enumLefRightBranch, // value && type == NULL
  enumRightBranch,
  enumValueLeftBranch,
  enumValueTypeOnly,
}; /* definition of ast Node type */

/* struct to represent the AST and nodes */
typedef struct parserNode {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  char* value;
  char* type;
} parserNode;

/* struct used as param during the parsing of the source code to create new nodes */
typedef struct astParam {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  char* value;
  char* type;
  char* astNodeClass;
  enum astNodeType nodeType;
} astParam;

parserNode* add_ast_node(astParam astParam) {
  parserNode *node = (parserNode *)calloc(1, sizeof(parserNode));

  switch (astParam.nodeType) {
    case enumLefRightBranch:
      printf("left right enum\n");
      break;
    case enumRightBranch:
      printf("right enum \n");
      break;
    case enumValueLeftBranch:
      printf("value left enum \n");
      break;
    default:
      break;
  }
  return node;
}