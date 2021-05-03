#include "tac.h"
#include "utlist.h"

tacLine *tacFileHead = NULL;

void insertTACLabel(char *label) {
  tacLine *tmpLine = (tacLine*)malloc(sizeof *tmpLine);
  utstring_new(tmpLine->codeLine);
  utstring_printf(tmpLine->codeLine, "%s:\n", label);
  printf("%s\n", utstring_body(tmpLine->codeLine));
  CDL_APPEND(tacFileHead, tmpLine);
}

void createTacFile(tacLine *tacFileHead) {
  tacLine *elt;
  FILE *fp;
  fp = fopen ("../examples/tac/output.tac", "w+");
  printf("\nCreating TAC file...\n");

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