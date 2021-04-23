#include "parser_ast.h"
#include "symbol_table.h"

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
    case enumLeftRightValueBranch:
      node->leftBranch = astParam.leftBranch;
      node->middle1Branch = NULL;
      node->middle2Branch = NULL;
      node->rightBranch = astParam.rightBranch;
      node->astNodeClass = astParam.astNodeClass;
      node->value = astParam.value;
      node->type = astParam.type;
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

void cast_operators(parserNode *left, parserNode *right) {
  scopeInfo current_scope = get_current_scope();
  struct symbolNode *leftSymbol, *rightSymbol;
  char leftType[6], rightType[6];
  if (strcmp(left->type, "IDENTIFIER")==0) {
    int *symbolkey, symbolID;
    symbolID = get_symbolID_by_name_and_current_scope(left->value, current_scope.scopeID, current_scope.level);
    symbolkey = &symbolID;
    HASH_FIND_INT(symbolTable, symbolkey, leftSymbol);
    strcpy(leftType, leftSymbol->type);
  }
  if (strcmp(right->type, "IDENTIFIER")==0) {
    int *symbolkey, symbolID;
    symbolID = get_symbolID_by_name_and_current_scope(right->value, current_scope.scopeID, current_scope.level);
    symbolkey = &symbolID;
    HASH_FIND_INT(symbolTable, symbolkey, rightSymbol);
    strcpy(rightType, rightSymbol->type);
  }
  if (strcmp(left->astNodeClass, "TERM")==0) {
    if (strcmp(left->type, "INT")==0) strcpy(leftType, "int");
    else if (strcmp(left->type, "FLOAT")==0) strcpy(leftType, "float");
    else if (strcmp(left->type, "ELEM")==0) strcpy(leftType, "elem");
    else if (strcmp(left->type, "SET")==0) strcpy(leftType, "set");
  }
  if (strcmp(right->astNodeClass, "TERM")==0) {
    if (strcmp(right->type, "INT")==0) strcpy(rightType, "int");
    else if (strcmp(right->type, "FLOAT")==0) strcpy(rightType, "float");
    else if (strcmp(right->type, "ELEM")==0) strcpy(rightType, "elem");
    else if (strcmp(right->type, "SET")==0) strcpy(rightType, "set");
  }

  if (strcmp(leftType, "int") == 0 && strcmp(rightType, "float") == 0) {
    left->cast = strdup("intToFloat");
  } else if (strcmp(leftType, "float") == 0 && strcmp(rightType, "int") == 0) {
    right->cast = strdup("intToFloat");
  }
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
    if (node->cast != NULL) {
      printf("CAST: %s - ", node -> cast);
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