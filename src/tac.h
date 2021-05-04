#ifndef TAC_H_
#define TAC_H_

#include <stdio.h>
#include <stdlib.h>
#include "utstring.h"
#include "utlist.h"

/* represents one element of the doubly linked list, i.e: one line of the TAC file */
typedef struct tacLine {
  UT_string *codeLine; /* string that represents one TAC line of code */
  struct tacLine *next, *prev; /* pointers to next and previos elements of the list */
}tacLine;

tacLine *tacFileHead; /* pointer to the head of the DLList that represents the TAC file */

enum tacCodeType {
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

/* adds symbols from the symbols table to the TAC file */
void addSymbolsToTable(FILE *file);

/* adds one line of code to TAC list */
void add_TAC_line(tacCodeParam tacCode);

/* insert label to tac file */
void insertTACLabel(char *label);

/* creates a TAC file, given a DLList of TACs */
void createTacFile(tacLine *tacFileHead);

/* releases memory alocated for the TAC list that represents TAC code */
void free_TAC_list(tacLine *tacFileHead);

#endif // TAC_