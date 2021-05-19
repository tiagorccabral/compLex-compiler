#include "tac.h"
#include "symbol_table.h"
#include "utlist.h"
#include "utstring.h"

tacLine *tacFileHead = NULL;

tacLine *tacFileTableHead = NULL;

codeLabelStack *codeStackHead = NULL;

int forLoopsCounter = 0;

void addSymbolToSetInfoTable(int setID, char *pointerToSet, int currentSize) {
  struct setInfo *symbolPointer;
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(setInfoTable, &setID, symbolPointer);
  if (symbolPointer == NULL) {
      symbolPointer = (setInfo*)malloc(sizeof(setInfo));
      symbolPointer -> setID = setID;
      symbolPointer -> current_size = currentSize;
      symbolPointer -> pointerToSet = pointerToSet;
      HASH_ADD_INT(setInfoTable, setID, symbolPointer);
  } else {
    printf("set symbol %d already declared!\n", setID);
  }
}

void increaseSetSize(int setID) {
  struct setInfo *symbolPointer;
  int backupCurrentSize;
  UT_string *bckupPointerToSet;
  utstring_new(bckupPointerToSet);
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(setInfoTable, &setID, symbolPointer);
  if (symbolPointer) {
      utstring_printf(bckupPointerToSet, "%s", symbolPointer->pointerToSet);
      backupCurrentSize = symbolPointer->current_size;
      HASH_DEL(setInfoTable, symbolPointer);
      addSymbolToSetInfoTable(setID, strdup(utstring_body(bckupPointerToSet)), backupCurrentSize+1);
  } else {
    printf("set symbol not found!\n");
  }
}

setInfo* getSetSymbolInfo(char *name) {
  int *symbolkey, symbolID;
  struct symbolNode *symbol;
  struct setInfo *setInfoPointer;
  scopeInfo current_scope = get_current_scope();
  symbolID = get_symbolID_by_name_and_current_scope(name, current_scope.scopeID, current_scope.level);
  if (symbolID != -1) {
    symbolkey = &symbolID;
    HASH_FIND_INT(symbolTable, symbolkey, symbol);
    if (symbol != NULL) {
      int *setInfoKey;
      setInfoKey = &(symbol->symbolID);
      HASH_FIND_INT(setInfoTable, setInfoKey, setInfoPointer);
      if (setInfoPointer != NULL) {
        printf("found symbol %d\n", symbol->symbolID);
        return setInfoPointer;
      }
    }
  }
  return setInfoPointer;
}

void addSymbolsToTable(FILE *fp) {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  tacLine *tmpElt;
  UT_string *lineOfCode;
  utstring_new(lineOfCode);

  int hasAtLeastOneVar = 0;
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if ((s->symbolType == enumVariable || s->symbolType == enumParameter) && hasAtLeastOneVar == 1) {
      if (strcmp(s->type, "set") == 0) utstring_printf(lineOfCode, "int %s\n", s->name);
      else utstring_printf(lineOfCode, "%s %s\n", s->type, s->name);
      fputs(utstring_body(lineOfCode), fp);
      utstring_clear(lineOfCode);
    } else if ((s->symbolType == enumVariable || s->symbolType == enumParameter) && hasAtLeastOneVar == 0) {
      hasAtLeastOneVar = 1;
      fputs(".table\n", fp);
      if (strcmp(s->type, "set") == 0) utstring_printf(lineOfCode, "int %s\n", s->name);
      else utstring_printf(lineOfCode, "%s %s\n", s->type, s->name);
      fputs(utstring_body(lineOfCode), fp);
      utstring_clear(lineOfCode);
    }
  }

  CDL_FOREACH(tacFileTableHead,tmpElt) {
    if (hasAtLeastOneVar == 1) {
      fputs(utstring_body(tmpElt->codeLine), fp);
    } else if (hasAtLeastOneVar == 0) {
      hasAtLeastOneVar = 1;
      fputs(".table\n", fp);
      fputs(utstring_body(tmpElt->codeLine), fp);
    }
  }

  utstring_free(lineOfCode);
}

void add_TAC_line(tacCodeParam tacCode) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);
  utstring_new(tmpLine->codeLine);
  switch (tacCode.lineType) {
    case enumNoOp:
      utstring_printf(tmpLine->codeLine, "%s\n", tacCode.instruction);
      break;
    case enumOneOp:
      utstring_printf(tmpLine->codeLine, "%s %s\n", tacCode.instruction, tacCode.op1);
      break;
    case enumTwoOp:
      utstring_printf(tmpLine->codeLine, "%s %s, %s\n", tacCode.instruction, tacCode.op1, tacCode.op2);
      break;
    case enumThreeOp:
      utstring_printf(tmpLine->codeLine, "%s %s, %s, %s\n", tacCode.instruction, tacCode.dst, tacCode.op1, tacCode.op2);
      break;
    default:
      break;
  }
  CDL_APPEND(tacFileHead, tmpLine);
}

void add_string_to_TAC(char *string, int writeLn, int *currentTempReg, int *currentTableCounter) {
  UT_string *stringPosition, *stringPointer, *stringValue, *comprTmp;
  UT_string *stringLen, *tmp, *labelStart, *labelFinish, *operand_array, *stringVar;
  utstring_new(stringPosition);utstring_new(stringPointer);
  utstring_new(stringValue);
  utstring_new(comprTmp);
  utstring_new(stringLen);
  utstring_new(operand_array);
  utstring_new(stringVar);
  create_temporary_register(stringPosition, currentTempReg);
  create_temporary_register(stringPointer, currentTempReg);
  create_temporary_register(stringValue, currentTempReg);
  create_temporary_register(comprTmp, currentTempReg);
  create_temporary_register(stringLen, currentTempReg);
  set_operand_array(operand_array, utstring_body(stringPointer), utstring_body(stringPosition));
  utstring_new(tmp);utstring_new(labelStart);utstring_new(labelFinish);utstring_new(stringVar);
  utstring_printf(tmp, "%lu", strlen(string)-1);
  utstring_printf(labelStart, "whileWritelnStart%d", *currentTableCounter);
  utstring_printf(labelFinish, "endWhileWriteln%d", *currentTableCounter);
  insert_string_to_TAC_table(stringVar, string, 0, currentTableCounter);
  tacCodeParam tacP0 = { .instruction = "mov", .op1 = utstring_body(stringLen), .op2 = utstring_body(tmp), .lineType=enumTwoOp};
  add_TAC_line(tacP0);
  tacCodeParam tacP = { .instruction = "mov", .op1 = utstring_body(stringPosition), .op2 = "0", .lineType=enumTwoOp};
  add_TAC_line(tacP);
  tacCodeParam tacP2 = { .instruction = "mov", .op1 = utstring_body(stringPointer), .op2 = utstring_body(stringVar), .lineType=enumTwoOp};
  add_TAC_line(tacP2);
  insertTACLabel(utstring_body(labelStart));
  tacCodeParam tacP4 = { .instruction = "seq", .dst= utstring_body(comprTmp),.op1 = utstring_body(stringLen), .op2 = utstring_body(stringPosition), .lineType=enumThreeOp};
  add_TAC_line(tacP4);
  tacCodeParam tacP5 = { .instruction = "brnz", .op1 = utstring_body(labelFinish), .op2 = utstring_body(comprTmp), .lineType=enumTwoOp};
  add_TAC_line(tacP5);
  tacCodeParam tacP3 = { .instruction = "mov", .op1 = utstring_body(stringValue), .op2 = utstring_body(operand_array), .lineType=enumTwoOp};
  add_TAC_line(tacP3);
  tacCodeParam tacP6 = { .instruction = "print", .op1 = utstring_body(stringValue), .lineType=enumOneOp};
  add_TAC_line(tacP6);
  tacCodeParam tacP7 = { .instruction = "add", .dst= utstring_body(stringPosition),.op1 = utstring_body(stringPosition), .op2 = "1", .lineType=enumThreeOp};
  add_TAC_line(tacP7);
  tacCodeParam tac8 = { .instruction = "jump", .op1 = utstring_body(labelStart), .lineType=enumOneOp};
  add_TAC_line(tac8);
  insertTACLabel(utstring_body(labelFinish));
  if (writeLn == 1) {
    tacCodeParam tacP9 = { .instruction = "print", .op1 = "'\\n'", .lineType=enumOneOp};
    add_TAC_line(tacP9);
  } else { /* need to add nop here to avoid case where 'write' op is last instruction, i.e: will have label followed by EOF */
    tacCodeParam tacP9 = { .instruction = "nop", .lineType=enumNoOp};
    add_TAC_line(tacP9);
  }
  utstring_free(operand_array); utstring_free(stringPosition); utstring_free(stringPointer);
  utstring_free(stringValue); utstring_free(stringLen); utstring_free(comprTmp);
  utstring_free(tmp); utstring_free(labelStart); utstring_free(labelFinish); utstring_free(stringVar);
}

void add_for_or_if_entry_to_TAC(char *string) {
  UT_string *labelStart;
  int stackSize = 0;
  codeLabelStack *codeLabel = (codeLabelStack *)malloc(sizeof *codeLabel);
  codeLabelStack *tmp;
  STACK_COUNT(codeStackHead, tmp, stackSize);
  utstring_new(labelStart);
  utstring_printf(labelStart, "%s%d%d", string, stackSize, forLoopsCounter);
  forLoopsCounter++;
  insertTACLabel(utstring_body(labelStart));
  codeLabel->name = utstring_body(labelStart);
  STACK_PUSH(codeStackHead, codeLabel);
}

void add_for_loop_closing_to_TAC(char *string, int *currentTempReg, parserNode *middle1Branch, parserNode *middle2Branch){
  UT_string *labelFinish;
  codeLabelStack *loopLabel;
  STACK_POP(codeStackHead, loopLabel);
  utstring_new(labelFinish);
  char *forIncrementOp = get_TAC_op_from_node_class(middle2Branch->leftBranch->astNodeClass);
  if (middle2Branch->leftBranch && middle2Branch->leftBranch->rightBranch && middle2Branch->leftBranch->rightBranch->tempReg) {
    tacCodeParam tacP0 = { .instruction = forIncrementOp, .dst= middle2Branch->value,.op1 = middle2Branch->value, .op2 = middle2Branch->leftBranch->rightBranch->tempReg, .lineType=enumThreeOp};
    add_TAC_line(tacP0);
  } else if (middle2Branch->leftBranch && middle2Branch->leftBranch->rightBranch && middle2Branch->leftBranch->rightBranch->value) {
    tacCodeParam tacP0 = { .instruction = forIncrementOp, .dst= middle2Branch->value,.op1 = middle2Branch->value, .op2 = middle2Branch->leftBranch->rightBranch->value, .lineType=enumThreeOp};
    add_TAC_line(tacP0);
  }
  tacCodeParam tac1 = { .instruction = "jump", .op1 = loopLabel->name, .lineType=enumOneOp};
  add_TAC_line(tac1);
  utstring_printf(labelFinish, "%sFinish", loopLabel->name);
  insertTACLabel(utstring_body(labelFinish));
  free(loopLabel->name);
  free(forIncrementOp);
  free(loopLabel);
  utstring_free(labelFinish);
}

char * get_TAC_op_from_node_class(char *node) {
  UT_string *operation;
  utstring_new(operation);
  if (strcmp(node, "ARITHMETIC_EXPRESSION ADD_OP") == 0) {
    utstring_printf(operation, "add");
  } else if (strcmp(node, "ARITHMETIC_EXPRESSION SUB_OP") == 0) {
    utstring_printf(operation, "sub");
  } else if (strcmp(node, "ARITHMETIC_EXPRESSION MULT_OP") == 0) {
    utstring_printf(operation, "mul");
  } else if (strcmp(node, "ARITHMETIC_EXPRESSION DIV_OP") == 0) {
    utstring_printf(operation, "div");
  }
  return utstring_body(operation);
}

void add_right_logical_loop_OP_to_TAC(char* op, parserNode *dst, parserNode *left, parserNode *right,int *currentTempReg, int *currentForLoop) {
  UT_string *label;
  utstring_new(label);
  codeLabelStack *loopLabel;
  loopLabel = STACK_TOP(codeStackHead);
  utstring_printf(label, "%sFinish%d", loopLabel->name, *currentForLoop - 1);
  if (left && right) {
    tacCodeValidationParams tacP = { .instruction = op, .dst= dst,.op1 = left, .op2=right, .lineType=enumThreeOp};
    check_ops_and_add_TAC_line(tacP);
  }
  utstring_free(label);
}

void add_if_else_entry_to_TAC() {
  UT_string *labelAfterElse;
  int stackSize = 0;
  codeLabelStack *tmp;
  STACK_COUNT(codeStackHead, tmp, stackSize);
  utstring_new(labelAfterElse);
  utstring_printf(labelAfterElse, "%s%d%d", "afterElseLabel", stackSize, forLoopsCounter);
  forLoopsCounter++;
  tacCodeParam tac0 = { .instruction = "jump", .op1 = utstring_body(labelAfterElse), .lineType=enumOneOp};
  add_TAC_line(tac0);

  UT_string *labelFinish;
  codeLabelStack *ifLabelStart;
  STACK_POP(codeStackHead, ifLabelStart);
  utstring_new(labelFinish);
  utstring_printf(labelFinish, "%sFinish", ifLabelStart->name);
  insertTACLabel(utstring_body(labelFinish));
  free(ifLabelStart->name);
  free(ifLabelStart);

  codeLabelStack *afterElseCodeLabel = (codeLabelStack *)malloc(sizeof *afterElseCodeLabel);
  afterElseCodeLabel->name = strdup(utstring_body(labelAfterElse));
  STACK_PUSH(codeStackHead, afterElseCodeLabel);
  utstring_free(labelAfterElse);
  utstring_free(labelFinish);
}

void add_if_else_closing_to_TAC() {
  if (STACK_TOP(codeStackHead)) {
    UT_string *labelFinish;
    codeLabelStack *elseLabelFinish;
    STACK_POP(codeStackHead, elseLabelFinish);
    utstring_new(labelFinish);
    utstring_printf(labelFinish, "%s", elseLabelFinish->name);
    insertTACLabel(utstring_body(labelFinish));
    free(elseLabelFinish->name);
    free(elseLabelFinish);
  }
}

void add_if_finish_to_TAC() {
  UT_string *label;
  utstring_new(label);
  codeLabelStack *ifLabel;
  ifLabel = STACK_TOP(codeStackHead);
  utstring_printf(label, "%sFinish", ifLabel->name);
  insertTACLabel(utstring_body(label));
  utstring_free(label);
}

void set_operand_array(UT_string *tmp, char *string, char *arrayPosition) {
  utstring_printf(tmp, "%s[%s]", string, arrayPosition);
}

char * insertTACLabel(char *label) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);
  utstring_new(tmpLine->codeLine);
  utstring_printf(tmpLine->codeLine, "%s:\n", label);
  CDL_APPEND(tacFileHead, tmpLine);
  return utstring_body(tmpLine->codeLine);
}

void insert_string_to_TAC_table(UT_string *stringVar, char *string, int pos, int *currentTableCounter) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);

  utstring_new(tmpLine->codeLine);
  utstring_printf(tmpLine->codeLine, "char string%d [] = %s\n", *currentTableCounter, string);

  utstring_printf(stringVar, "&string%d", *currentTableCounter);
  *currentTableCounter = *currentTableCounter + 1;

  CDL_APPEND(tacFileTableHead, tmpLine);
}

void set_temporary_register(parserNode *node, int *currentTempReg) {
  UT_string *tmp;
  utstring_new(tmp);
  utstring_printf(tmp, "$%d", *currentTempReg);
  node->tempReg = strdup(utstring_body(tmp));
  *currentTempReg = *currentTempReg + 1;
  utstring_free(tmp);
}

void create_temporary_register(UT_string *string, int *currentTempReg) {
  utstring_printf(string, "$%d", *currentTempReg);
  *currentTempReg = *currentTempReg + 1;
}

void set_param(UT_string *string, parserNode *node, int *currentParamsReg) {
  utstring_printf(string, "#%d", *currentParamsReg);
  node->tempReg = utstring_body(string);
  *currentParamsReg = *currentParamsReg + 1;
}

void stringify_integer(UT_string *string, int number_to_be_string) {
  utstring_printf(string, "%d", number_to_be_string);
}

void check_ops_and_add_TAC_line(tacCodeValidationParams validationParams) {
  switch (validationParams.lineType) {
  case enumOneOp:
    if (validationParams.op1->value && validationParams.op1->tempReg) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .op1 = validationParams.op1->tempReg, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->value) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .op1 = validationParams.op1->value, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->tempReg) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .op1 = validationParams.op1->tempReg, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    }
    break;
  case enumTwoOp:
    break;
  case enumThreeOp:
    if (validationParams.op1->value && validationParams.op2->value && validationParams.op1->tempReg && validationParams.op2->tempReg) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->tempReg, .op2 = validationParams.op2->tempReg, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->value && validationParams.op2->tempReg) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->value, .op2 = validationParams.op2->tempReg, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->tempReg && validationParams.op2->value) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->tempReg, .op2 = validationParams.op2->value, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->tempReg && validationParams.op2->tempReg) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->tempReg, .op2 = validationParams.op2->tempReg, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    } else if (validationParams.op1->value && validationParams.op2->value) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->value, .op2 = validationParams.op2->value, .lineType=validationParams.lineType};
      add_TAC_line(tacP);
    }
    break;
  default:
    break;
  }
}

void createTacFile(tacLine *tacFileHead) {
  tacLine *elt;
  FILE *fp;
  fp = fopen ("../examples/tac/output.tac", "w+");
  printf("\nCreating TAC file...\n");

  addSymbolsToTable(fp); /* adds .table section, if it exists */

  fputs(".code\n", fp); /* creates .code portion of TAC */

  insertTACLabel("main"); /* create TAC file main label first */

  tacCodeParam tacP = { .instruction = "call", .op1 = "fmain", .lineType=enumOneOp};
  add_TAC_line(tacP);
  tacCodeParam tacP1 = { .instruction = "nop", .lineType=enumNoOp};
  add_TAC_line(tacP1);

  CDL_FOREACH(tacFileHead,elt) {
    fputs(utstring_body(elt->codeLine), fp);
  }

  printf("Done!\n");
  fclose(fp);
}

void free_TAC_list(tacLine *tacFileHead) {
  tacLine *elt, *tmp, *etmp;

  CDL_FOREACH_SAFE(tacFileHead,elt,tmp, etmp) {
    CDL_DELETE(tacFileHead,elt);
    utstring_free(elt->codeLine);
    free(elt);
  }
}

void free_TAC_table_list(tacLine *tacFileTableHead) {
  tacLine *elt, *tmp, *etmp;
  codeLabelStack *stackElt;

  CDL_FOREACH_SAFE(tacFileTableHead,elt,tmp, etmp) {
    CDL_DELETE(tacFileTableHead,elt);
    utstring_free(elt->codeLine);
    free(elt);
  }

  while (!STACK_EMPTY(codeStackHead)) {
    STACK_POP(codeStackHead, stackElt);
    free(stackElt->name);
    free(stackElt);
  }
}

void free_setInfo_table() {
  setInfo *s, *tmp;
  HASH_ITER(hh, setInfoTable, s, tmp) {
    HASH_DEL(setInfoTable, s);
    free(s);
  }
}