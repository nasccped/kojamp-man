#ifndef _ENVIRONMENT_H_ // if environment.h isn't already defined
#define _ENVIRONMENT_H_ // define it

// log.h contents will be necessary, so:
#ifndef _LOG_H_     // if log.h isn't already defined
  #include "log.h"  // include it
#endif

// stdbool.h contents will be necessary, so:
#ifndef _STDBOOL_H_
  #include <stdbool.h> // include stdbool too
#endif

// main function at environment.c
void environment_main(struct LogList *dest);

// defining our constants -------------------------------------------
#if (defined _WIN32) || (defined _WIN64)
  static const char *DIRECTORY_SEPARATOR = "\\";
#else
  static const char *DIR_SEPARATOR = "/";
#endif

// expected dirs
static const char *GO_BACK_A_DIR    = ".."   ;
static const char *EXPECTED_OUT_DIR = "out"  ;
static const char *EXPECTED_GIT_DIR = ".git" ;
static const char *EXPECTED_SRC_DIR = "src"  ;
static const char *EXPECTED_STP_DIR = "setup";

// max length that a directory path can store
#define DIR_MAX_LENGHT 300

// exporting our variables ------------------------------------------
extern char KOJAMP_ROT_DIR[DIR_MAX_LENGHT];
extern char KOJAMP_BIN_DIR[DIR_MAX_LENGHT];
extern char KOJAMP_OUT_DIR[DIR_MAX_LENGHT];
extern char KOJAMP_GIT_DIR[DIR_MAX_LENGHT];
extern char KOJAMP_SRC_DIR[DIR_MAX_LENGHT];
extern char KOJAMP_STP_DIR[DIR_MAX_LENGHT];

#endif
