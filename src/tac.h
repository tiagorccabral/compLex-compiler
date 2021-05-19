#ifndef TAC_H_
#define TAC_H_

#include <stdio.h>
#include <stdlib.h>
#include "parser_ast.h"
#include "utstring.h"
#include "utlist.h"
#include "utstack.h"
#include "uthash.h"

/* keeps track of current for coode stack name */
typedef struct codeLabelStack {
  char* name; /* name of current code scope stack */
  struct codeLabelStack *next;
} codeLabelStack; /* element of each scope stack of for code */

/* represents one element of the doubly linked list, i.e: one line of the TAC file */
typedef struct tacLine {
  UT_string *codeLine; /* string that represents one TAC line of code */
  struct tacLine *next, *prev; /* pointers to next and previos elements of the list */
}tacLine;

/* hash table with info about dynamic sets */
typedef struct setInfo {
  int setID; /* required key ID from documentation */
  int current_size; /* current size of set */
  char* pointerToSet; /* tempReg pointing to SET */
  UT_hash_handle hh; /* makes this structure hashable */
} setInfo;

setInfo *setInfoTable; /* pointer to set info table */

codeLabelStack *codeStackHead; /* pointer to the head of the stack of labels of loops and ifs */

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

int forLoopsCounter;

/* add set to set info table */
void addSymbolToSetInfoTable(int setID, char *pointerToSet, int currentSize);

/* increase current set size + 1 of given ID on the hash table */
void increaseSetSize(int setID);

/* get set to set info table */
setInfo* getSetSymbolInfo(char *name);

/* adds symbols from the symbols table to the TAC file */
void addSymbolsToTable(FILE *file);

/* adds one line of code to TAC list */
void add_TAC_line(tacCodeParam tacCode);

/* insert label to tac file */
char * insertTACLabel(char *label);

/* insert a string to the .table portion of the TAC file, modifies name of created .table var to stringVar */
void insert_string_to_TAC_table(UT_string *stringVar, char *string, int pos, int *currentTableCounter);

/* sets a temporary register to a given node */
void set_temporary_register(parserNode *node, int *currentTempReg);

/* creates a new temporary register, returns string of that register */
void create_temporary_register(UT_string *string, int *currentTempReg);

/* sets a temporary register to a given node representing the param of a function, returns string of that register */
void set_param(UT_string *string, parserNode *node, int *currentParamsReg);

/* add instructions to TAC to print a simple string to terminal. If writeln is 1, add a \n to end of string */
void add_string_to_TAC(char *string, int writeLn, int *currentTempReg, int *currentTableCounter);

/* adds initial part of 'if' or 'for loop' to TAC file, given a string */
void add_for_or_if_entry_to_TAC(char *string);

/* adds closing part of for loop to TAC file, given a string */
void add_for_loop_closing_to_TAC(char *string, int *currentTempReg, parserNode *middle1Branch, parserNode *middle2Branch);

void add_right_logical_loop_OP_to_TAC(char* op, parserNode *dst, parserNode *left, parserNode *right,int *currentTempReg, int *currentForLoop);

void add_if_else_entry_to_TAC();

void add_if_else_closing_to_TAC();

void add_if_finish_to_TAC();

char * get_TAC_op_from_node_class(char *node);

/* creates a string that is in the format of array access */
void set_operand_array(UT_string *, char *, char *);

/* takes a number, and returns the string version of that number */
void stringify_integer(UT_string *string, int number_to_be_string);

/* check operands and calls add_TAC_line with correct params */
void check_ops_and_add_TAC_line(tacCodeValidationParams validationParams);

/* creates a TAC file, given a DLList of TACs */
void createTacFile(tacLine *tacFileHead);

/* releases memory alocated for the TAC list that represents TAC code */
void free_TAC_list(tacLine *tacFileHead);

/* releases memory alocated for the TAC list that represents TAC .table */
void free_TAC_table_list(tacLine *tacFileTableHead);

void free_setInfo_table();

#endif // TAC_