#include <stdio.h>
#include <stdlib.h>

enum astNodeType {
  enumLeftRightBranch,         // value && type == NULL
  enumLeftRightMiddleBranch,   // value && type == NULL
  enumRightBranch,            // left branch && value && type == NULL
  enumValueLeftBranch,        // right branch == NULL
  enumValueTypeOnly,          // right && left branch == NULL
}; /* definition of ast Node type */

/* struct to represent the AST and nodes */
typedef struct parserNode {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  struct parserNode* middleBranch;
  char* value;
  char* type;
  char* astNodeClass;
} parserNode;

/* struct used as param during the parsing of the source code to create new nodes */
typedef struct astParam {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  struct parserNode* middleBranch;
  char* value;
  char* type;
  char* astNodeClass;
  enum astNodeType nodeType;
} astParam;

parserNode* add_ast_node(astParam astParam) {
  parserNode *node = (parserNode *)calloc(1, sizeof(parserNode));

  printf("astParam: %d\n", astParam.nodeType);
  switch (astParam.nodeType) {
    case enumLeftRightMiddleBranch:
      node->leftBranch = astParam.leftBranch;
      node->middleBranch = astParam.middleBranch;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      printf("left right and middle enum ast node class: %s\n", node->astNodeClass);
      break;
    case enumLeftRightBranch:
      node->leftBranch = astParam.leftBranch;
      node->middleBranch = NULL;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = NULL;
      node->type = NULL;
      printf("left right enum ast node class: %s\n", node->astNodeClass);
      break;
    case enumRightBranch:
      node->astNodeClass = astParam.astNodeClass;
      printf("right enum \n");
      break;
    case enumValueLeftBranch:
      node->leftBranch = astParam.leftBranch;
      node->middleBranch = NULL;
      node->rightBranch = NULL;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      printf("value left enum \n");
      break;
    case enumValueTypeOnly:
      node->leftBranch = NULL;
      node->middleBranch = NULL;
      node->rightBranch = NULL;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      printf("value type enum \n");
      break;
    default:
      break;
  }
  return node;
}

void print_parser_ast(parserNode *node) {
  if (node) {
    if (node->type != NULL) {
      printf("type: %s - ", node -> type);
    }
    if (node->value != NULL) {
      printf("value: %s - ", node -> value);
    }
    if (node->astNodeClass != NULL) {
      printf("class: %s \n", node -> astNodeClass);
    }
    print_parser_ast(node -> leftBranch);
    print_parser_ast(node -> middleBranch);
    print_parser_ast(node -> rightBranch);
  }
}