#ifndef TAC_H_
#define TAC_H_

#include <stdio.h>
#include <stdlib.h>
#include "parser_ast.h"
#include "utstring.h"
#include "utlist.h"
#include "utstack.h"

/* keeps track of current for loop stack name */
typedef struct forLoopStack {
  char* name; /* name of current for loop scope stack */
  struct forLoopStack *next;
} forLoopStack; /* element of each scope stack of for loops */

/* represents one element of the doubly linked list, i.e: one line of the TAC file */
typedef struct tacLine {
  UT_string *codeLine; /* string that represents one TAC line of code */
  struct tacLine *next, *prev; /* pointers to next and previos elements of the list */
}tacLine;

forLoopStack *forLoopStackHead; /* pointer to the head of the stack of labels of ForLoops */

tacLine *tacFileHead; /* pointer to the head of the DLList that represents the TAC file */

tacLine *tacFileTableHead; /* pointer to the head of the DLList that represents the .table section of the TAC file */

enum tacCodeType {
  enumNoOp, /* 0 operand instruction, e.g: nop */   
  enumOneOp, /* one operand instruction, e.g: jump <op1> */   
  enumTwoOp, /* two operand instruction, e.g: brnz <op2>, <op1> */
  enumThreeOp, /* three operand instruction, e.g: add <dst>, <op1>, <op2> */
}; /* definition of types of instructions */

/* struct used as param for creation of TAC code line */
typedef struct tacCodeParam {
  char* instruction;
  char* dst;
  char* op1;
  char* op2;
  enum tacCodeType lineType;
} tacCodeParam;

/* struct used as param for check_ops_add_TAC_line function */
typedef struct tacCodeValidationParams {
  char* instruction;
  struct parserNode* dst;
  struct parserNode* op1;
  struct parserNode* op2;
  enum tacCodeType lineType;
} tacCodeValidationParams;

/* adds symbols from the symbols table to the TAC file */
void addSymbolsToTable(FILE *file);

/* adds one line of code to TAC list */
void add_TAC_line(tacCodeParam tacCode);

/* insert label to tac file */
char * insertTACLabel(char *label);

/* insert a string to the .table portion of the TAC file, returns name of created .table var */
char* insert_string_to_TAC_table(char *string, int pos, int *currentTableCounter);

/* sets a temporary register to a given node, returns string of that register */
char * set_temporary_register(parserNode *node, int *currentTempReg);

/* creates a new temporary register, returns string of that register */
char * create_temporary_register(int *currentTempReg);

/* sets a temporary register to a given node representing the param of a function, returns string of that register */
char * set_param(parserNode *node, int *currentParamsReg);

/* add instructions to TAC to print a simple string to terminal. If writeln is 1, add a \n to end of string */
void add_string_to_TAC(char *string, int writeLn, int *currentTempReg, int *currentTableCounter);

/* adds initial part of for loop to TAC file, given a string */
void add_for_loop_entry_to_TAC(char *string, int *currentForLoop);

/* adds closing part of for loop to TAC file, given a string */
void add_for_loop_closing_to_TAC(char *string, int *currentForLoop, int *currentTempReg, parserNode *middle1Branch, parserNode *middle2Branch);

void add_right_logical_loop_OP_to_TAC(char* op, parserNode *dst, parserNode *left, parserNode *right,int *currentTempReg, int *currentForLoop);

/* creates a string that is in the format of array access */
char * set_operand_array(char *string, char *arrayPosition);

/* takes a number, and returns the string version of that number */
char * stringify_integer(int number_to_be_string);

/* check operands and calls add_TAC_line with correct params */
void check_ops_and_add_TAC_line(tacCodeValidationParams validationParams);

/* creates a TAC file, given a DLList of TACs */
void createTacFile(tacLine *tacFileHead);

/* releases memory alocated for the TAC list that represents TAC code */
void free_TAC_list(tacLine *tacFileHead);

/* releases memory alocated for the TAC list that represents TAC .table */
void free_TAC_table_list(tacLine *tacFileTableHead);

#endif // TAC_