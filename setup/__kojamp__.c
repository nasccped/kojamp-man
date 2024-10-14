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
#ifndef __INCLUDE__H_
  #include "headers/_include_.h"    // _include_ (cointains all includes)
#endif

#ifndef _ENVIRONMENT_H_
  #include "headers/environment.h"  // environment (extern vars and defines)
#endif

#ifndef _LOG_H_
  #include "headers/log.h"          // log (structs, enums, functions declarations, etc)
#endif

// main function
int main(int argc, char *argv[]) {

  // break line
  printf("\n");

  // building all Logs constants
  log_main();

  environment_main(&ENV_CHECKER_LOGLIST);

  // let's display all Log from our LogList
  display_loglist(&ENV_CHECKER_LOGLIST);

  // break line
  printf("\n");

  return 0;
}
