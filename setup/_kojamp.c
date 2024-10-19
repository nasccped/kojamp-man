// conditional includes to prevent redundant imports
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

// main function
int main(int argc, char *argv[]) {

  printf("\n");

  // if at least one arg was provided
  if (argc > 1) {

    // take that arg and continues
    char *arg = argv[1];

    if (find_char_on_array(arg, BINARY_CMD_EXPECTED    ,
                                BINARY_CMD_EXPECTED_LEN))
      binary();

    else {
      printf("Can't find command to given argument(s): %s",
             ESCAPE_DEFT_RED);

      for (int i = 1; i < argc; i++)
        printf("%s ", argv[i]);

      printf("%s\n", ESCAPE_RESET);
      printf("\nTry %skojamp --binary%s %s(or -B)%s instead!\n"        ,
             ESCAPE_BOLD_GREEN, ESCAPE_RESET, ESCAPE_ITAL, ESCAPE_RESET);
    }

  } else
    printf("No argument given! Try kojamp %s<something>%s instead...\n",
           ESCAPE_ITAL, ESCAPE_RESET);

  // break a line
  printf("\n");

  // return int
  return 0;
}
