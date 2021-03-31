#include <stdio.h>

/*
 If debug == 1, will print msg
 otherwise will not
*/
void print_parser_msg(char* msg, int debug) {
  if (debug == 1) {
    printf("%s\n", msg);
  }
}