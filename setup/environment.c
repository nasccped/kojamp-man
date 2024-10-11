#include "headers/_include_.h"
#include "headers/environment.h"

// variable call ----------------------------------------------------
char KOJAMP_BINARY_DIRECTORY[MAX_DIRECTORY_LENGTH];

/* Function: environment_run
 * -------------------------
 *  Run the environment initial tasks, such as:
 *    - get binary directory
 *    - get output directory
 *    - get .git directory
 *
 *  It will start an empty LogList variable with:
 *    - string     title
 *    - malloc'ed  array
 *    - 0          length
 *    - function   pointer
 *
 *  For each subtask done, will append a Log struct pointer to the
 *  LogList array. the Log struct will contain:
 *
 *    - enum  Status   < OK | FAIL | WARNING | NONE >
 *    - char* message  < some text description of the subtask >
 *    ---------------------------------------------------------
 *    The Status value will be acording on subtask situation
 *
 *  If something goes wrong, all pointers in LogArray will be free'd,
 *  length (LogArray size) will be updated to -1 and the LogList
 *  variable will be returned immediately
 *
 *  Don't worry. Everything will work. It will return a -1 lenght
 *  only if a memory allocation error or something related occurs
 * --------------------------------------------------------------- */
struct LogList environment_run() {

  // starting our LogList variable with empty values:
  struct LogList returnable = {
    "Environment Checker"         , // LogList    title
    (Log **)malloc(sizeof(Log **)), // malloc'ed  array
    0                             , // 0          size
    append_log                      // append_log function
  };

  // appending some test values
  returnable.append_log(&returnable, OK     ,"Everythin is OK"     );
  returnable.append_log(&returnable, WARNING,"Something went wrong");
  returnable.append_log(&returnable, NONE   ,"Nothing to say"      );

  // returning our LogList variable
  return returnable;
}
