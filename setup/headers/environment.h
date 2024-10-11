#ifndef _ENVIRONMENT_H_ // if environment.h isn't already defined
#define _ENVIRONMENT_H_ // define it

// log.h contents will be necessary, so:
#ifndef _LOG_H_     // if log.h isn't already defined
  #include "log.h"  // include it
#endif

// main function at environment.c (it will return a LogList struct)
struct LogList environment_run(void);

// defining our constants -------------------------------------------
#if (defined _WIN32) || (defined _WIN64)
  static const char *DIRECTORY_SEPARATOR = "\\";
#else
  static const char *DIRECTORY_SEPARATOR = "/";
#endif

static const char *GO_BACK_A_DIRECTORY = ".."   ;
static const char *EXPECTED_OUT_NAME   = "out"  ;
static const char *EXPECTED_GIT_NAME   = ".git" ;
static const char *EXPECTED_SRC_NAME   = "src"  ;
static const char *EXPECTED_STP_NAME   = "setup";

// max length that a directory path can store
#define MAX_DIRECTORY_LENGTH 250

// exporting our variables ------------------------------------------
extern char KOJAMP_BINARY_DIRECTORY[MAX_DIRECTORY_LENGTH];
extern char KOJAMP_OUTPUT_DIRECTORY[MAX_DIRECTORY_LENGTH];
extern char KOJAMP_GIT_DIRECTORY[MAX_DIRECTORY_LENGTH]   ;
extern char KOJAMP_SOURCE_DIRECTORY[MAX_DIRECTORY_LENGTH];
extern char KOJAMP_SETUP_NAME[MAX_DIRECTORY_LENGTH]      ;

#endif
