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
// including all needed header files
#include "headers/_include_.h"    // _include_ (cointains all includes)
#include "headers/environment.h"  // environment (extern vars and defines)
#include "headers/log.h"          // log (structs, enums, functions declarations, etc)

// main function
int main(int argc, char *argv[]) {

  // break line
  printf("\n");

  // creating our environment LogList
  struct LogList env_loglist = environment_run();

  // let's display all Log from our LogList
  display_loglist(&env_loglist);

  // we can't forget to free our pointers :^)
  free_loglist(&env_loglist, true);

  // break line
  printf("\n");

  return 0;
}
