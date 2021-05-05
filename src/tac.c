#include "tac.h"
#include "symbol_table.h"
#include "utlist.h"

tacLine *tacFileHead = NULL;

void addSymbolsToTable(FILE *fp) {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  UT_string *lineOfCode;
  utstring_new(lineOfCode);

  int hasAtLeastOneVar = 0;
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (s->symbolType == enumVariable && hasAtLeastOneVar == 1) {
      utstring_printf(lineOfCode, "%s %s\n", s->type, s->name);
      fputs(utstring_body(lineOfCode), fp);
      utstring_clear(lineOfCode);
    } else if (s->symbolType == enumVariable && hasAtLeastOneVar == 0) {
      hasAtLeastOneVar = 1;
      fputs(".table\n", fp);
      utstring_printf(lineOfCode, "%s %s\n", s->type, s->name);
      fputs(utstring_body(lineOfCode), fp);
      utstring_clear(lineOfCode);
    }
  }

  utstring_free(lineOfCode);
}

void add_TAC_line(tacCodeParam tacCode) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);
  utstring_new(tmpLine->codeLine);
  switch (tacCode.lineType) {
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

void insertTACLabel(char *label) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);
  utstring_new(tmpLine->codeLine);
  utstring_printf(tmpLine->codeLine, "%s:\n", label);
  CDL_APPEND(tacFileHead, tmpLine);
}

void check_ops_and_add_TAC_line(tacCodeValidationParams validationParams) {
  switch (validationParams.lineType) {
  case enumOneOp:
    /* code */
    break;
  case enumTwoOp:
    break;
  case enumThreeOp:
    if (validationParams.op1->value && validationParams.op2->value) {
      tacCodeParam tacP = { .instruction=validationParams.instruction, .dst= validationParams.dst->tempReg,.op1 = validationParams.op1->value, .op2 = validationParams.op2->value, .lineType=validationParams.lineType};
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