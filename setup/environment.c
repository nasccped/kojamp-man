// our conditional imports ------------------------------------------
#ifndef __INCLUDE__H_
  #include "headers/_include_.h" // _include_.h
#endif

#ifndef _LOG_H_
  #include "headers/log.h" // log.h
#endif

#ifndef _ENVIRONMENT_H_
  #include "headers/environment.h" // environment
#endif

// variable call ----------------------------------------------------
char KOJAMP_ROT_DIR[DIR_MAX_LENGHT];
char KOJAMP_BIN_DIR[DIR_MAX_LENGHT];

/* Function: environment_run
 * -------------------------
 *  Run the environment initial tasks, such as:
 *    - get necessary directories
 *
 *  It will take a LogList struct pointer argument and append
 *  pointer values to it by doing subtasks:
 *
 *  The pointer to be appended is a Log struct pointer type. The Log
 *  struct will contain:
 *
 *    - enum   Status   < OK | FAIL | WARNING | NONE >
 *    - char **message  < some text description of the subtask >
 *    ----------------------------------------------------------
 *    The Status value will be acording on subtask situation
 * --------------------------------------------------------------- */
void environment_main(struct LogList *dest) {

  // if given pointer is null, abort function
  if (dest == NULL)
    return;

  // if getcwd result in a error (NULL)
  if (getcwd(KOJAMP_BIN_DIR, DIR_MAX_LENGHT) == NULL) {

    // append this Log to the List
    append_log(dest, &BIN_DIR_IS_NULL);

    // abort function (operations can't continue with an invalid bin
    // path)
    return;
  }

  // if our final LogList is empty
  if (dest -> linked_logs == NULL)
    append_log(dest, &LOGLIST_IS_EMPTY); // append 'NO ERRORS' log
}
