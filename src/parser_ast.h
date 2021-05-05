#ifndef PARSER_AST_H_
#define PARSER_AST_H_

#include <stdio.h>
#include <stdlib.h>

enum astNodeType {
  enumLeftRightMiddle1And2Branch,   // value && type == NULL
  enumLeftRightMiddleBranch,   // value && type == NULL
  enumLeftRightBranch,         // value && type == NULL
  enumLeftRightValueBranch,    // middle 1 and 2 null
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
  char* tempReg;
  char* cast;
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

/* returns one node of the AST based on astParam */
parserNode* add_ast_node(astParam astParam);

/* verifies the need of casting operators on of the AST, and if they need mark that in the correspondent node */
/* returns 1 if contains error, 0 if Ok */
int cast_operators(parserNode *left, parserNode *right, int line);

/* sets a temporary register to a given node, returns current Temp reg + 1 */
int set_temporary_register(parserNode *node, int currentTempReg);

/* prints the AST to the terminal, first param is the root node, second param the initial level (depth) of that node */
void print_parser_ast(parserNode *node, int level);

/* releases memory alocated for AST */
void free_parser_ast(parserNode *node);

#endif // PARSER_AST_