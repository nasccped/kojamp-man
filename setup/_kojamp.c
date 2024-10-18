#ifndef __INCLUDE__H_
  #include "headers/_include_.h"
#endif

#ifndef _BINARY_H_
  #include "headers/binary.h"
#endif

#ifndef _FUNCTIONS_H_
  #include "headers/functions.h"
#endif

#ifndef _CONSTS_H_
  #include "headers/consts.h"
#endif

int main(int argc, char *argv[]) {

  printf("\n");

  if (argc > 1) {

    char *arg = argv[1];

    if (find_char_on_array(arg, BINARY_CMD_EXPECTED    ,
                                BINARY_CMD_EXPECTED_LEN))
      binary();
    else {
      printf("Can't find command to given argument: %s%s%s\n",
             ESCAPE_DEFT_RED, arg, ESCAPE_RESET              );

      printf("\nTry %skojamp --binary%s %s(or -B)%s instead!\n"        ,
             ESCAPE_BOLD_GREEN, ESCAPE_RESET, ESCAPE_ITAL, ESCAPE_RESET);
    }
  }
  else
    printf("No argument given! Try kojamp %s<something>%s instead...\n",
           ESCAPE_ITAL, ESCAPE_RESET);

  printf("\n");

  return 0;
}
