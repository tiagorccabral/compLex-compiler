#include <stdio.h>
#include <stdlib.h>

enum astNodeType {
  enumLeftRightMiddle1And2Branch,   // value && type == NULL
  enumLeftRightMiddleBranch,   // value && type == NULL
  enumLeftRightBranch,         // value && type == NULL
  enumValueLeftBranch,        // right branch == NULL
  enumValueTypeOnly,          // right && left branch == NULL
}; /* definition of ast Node type */

/* struct to represent the AST and nodes */
typedef struct parserNode {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  struct parserNode* middle1Branch;
  struct parserNode* middle2Branch;
  char* value;
  char* type;
  char* astNodeClass;
} parserNode;

/* struct used as param during the parsing of the source code to create new nodes */
typedef struct astParam {
  struct parserNode* rightBranch;
  struct parserNode* leftBranch;
  struct parserNode* middle1Branch;
  struct parserNode* middle2Branch;
  char* value;
  char* type;
  char* astNodeClass;
  enum astNodeType nodeType;
} astParam;

parserNode* add_ast_node(astParam astParam) {
  parserNode *node = (parserNode *)calloc(1, sizeof(parserNode));

  switch (astParam.nodeType) {
    case enumLeftRightMiddle1And2Branch:
      node->leftBranch = astParam.leftBranch;
      node->middle1Branch = astParam.middle1Branch;
      node->middle2Branch = astParam.middle2Branch;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      break;
    case enumLeftRightMiddleBranch:
      node->leftBranch = astParam.leftBranch;
      node->middle1Branch = astParam.middle1Branch;
      node->middle2Branch = NULL;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      break;
    case enumLeftRightBranch:
      node->leftBranch = astParam.leftBranch;
      node->middle1Branch = NULL;
      node->middle2Branch = NULL;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = NULL;
      node->type = NULL;
      break;
    case enumValueLeftBranch:
      node->leftBranch = astParam.leftBranch;
      node->middle1Branch = NULL;
      node->middle2Branch = NULL;
      node->rightBranch = NULL;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      break;
    case enumValueTypeOnly:
      node->leftBranch = NULL;
      node->middle1Branch = NULL;
      node->middle2Branch = NULL;
      node->rightBranch = NULL;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
      break;
    default:
      break;
  }
  return node;
}

void print_parser_ast(parserNode *node, int level) {
  if (node) {
    for (int aux = level; aux > 0; aux--) {
      printf("%s", "~");
    }
    printf("> ");
    printf("class: %s - ", node -> astNodeClass);
    if (node->type != NULL) {
      printf("type: %s - ", node -> type);
    }
    if (node->value != NULL) {
      printf("value: %s - ", node -> value);
    }
    printf("\n");
    print_parser_ast(node -> leftBranch, level + 1);
    print_parser_ast(node -> middle1Branch, level + 1);
    print_parser_ast(node -> middle2Branch, level + 1);
    print_parser_ast(node -> rightBranch, level + 1);
  }
}

void free_parser_ast(parserNode *node) {
  if (node == NULL) {
    return;
  }
  if (node -> leftBranch) {
    free_parser_ast(node->leftBranch);
  }
  if (node -> middle1Branch) {
    free_parser_ast(node->middle1Branch);
  }
  if (node -> middle2Branch) {
    free_parser_ast(node->middle2Branch);
  }
  if (node -> rightBranch) {
    free_parser_ast(node->rightBranch);
  }
  free(node);
}