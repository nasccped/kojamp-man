/* ------------------------------------------------------------------
 *
 * kojamp.c
 *
 *    Here's the program C file that will be turned into an
 *    executable!
 *
 *    Although the project is developed mainly in the Java language,
 *    a binary file is needed for everything to work the way it
 *    should. So, here is the program!
 *
 * ----------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define TEST_ESCAPE "\033[3m"
#define RSET_ESCAPE "\033[0m"

int main(int argc, char *argv[]) {

  // FIX: still in tests!
  printf("Hello world, from C Lang\n\n");

  printf("Let's run a Java program? %s(y: yes, n: no)%s\n",
         TEST_ESCAPE, RSET_ESCAPE);

  char response;
  scanf("%c", &response);

  printf("\n");

  if (response == 'n') {

    printf("Sure! Quitting");

  } else if (response == 'y') {

    char java_command[] = "java --class-path out Main";

    system(java_command);

  } else {

    printf("'Da heel bro '-'");
  }

  printf("\n\n");

  return 0;
}
