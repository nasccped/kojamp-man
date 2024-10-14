// our conditional includes -----------------------------------------
#ifndef __INCLUDE__H_
  #include "headers/_include_.h" // _include_.h
#endif

#ifndef _LOG_H_
  #include "headers/log.h"       // log.h
#endif

#ifndef _COLORS_H_
  #include "headers/colors.h"    // colors.h
#endif

// variable call ----------------------------------------------------
char HOLD_ESCAPE[MAX_ESCAPE_LENGTH ];
char STATUS_TEXT[STATUS_TEXT_LENGTH];
struct Log LOGLIST_IS_EMPTY;
struct Log BIN_DIR_IS_NULL ;

/* Function: log_main
 * ------------------
 *  This function store values in all Log structs that will be used
 *  by the program.
 *
 *  Return nothing. Just update the values
 */
void log_main() {

  LOGLIST_IS_EMPTY.status   = OK            ;
  LOGLIST_IS_EMPTY.message  = LOG_IS_EMP_STR;

  BIN_DIR_IS_NULL.status  = FAIL              ;
  BIN_DIR_IS_NULL.message = BIN_DIR_IS_NLL_STR;

}

/* Function: append_log
 * --------------------
 *  This function receive 2 arguments:
 *    - self    : LogList struct pointer
 *    - new_log : Log struct pointer
 *
 *  This function doesn't return nothing, just take the LogList
 *  pointer and iterate on it until get the NULL Log pointer. Then,
 *  insert the *new_log to this pointer
 * --------------------------------------------------------------- */
void append_log(struct LogList *self, struct Log *new_log) {

  // if invalid address
  if (self == NULL || new_log == NULL)
    return; // return function

  // if LogList is empty
  if (self -> linked_logs == NULL) {
    self -> linked_logs = new_log; // insert at linked_log root
    return                       ; // break the function
  }

  // else, copy the first linked_log pointer
  struct Log *pnt = self -> linked_logs;

  // while next log is not null
  while (pnt -> next_log != NULL)
    pnt = pnt -> next_log; // take it

  // insert *new_log as `next_log`
  pnt -> next_log = new_log;
}

/* Function: display_loglist
 * -------------------------
 *  This function receive just one argument:
 *    - self: LogList struct pointer
 *
 *  The purpose of this function is only display the LogList title
 *  and each element inside it.
 * --------------------------------------------------------------- */
void display_loglist(struct LogList *self) {

  // if invalid pointer
  if (self == NULL)
    return; // return

  // clear HOLD_ESCAPE
  strcpy(HOLD_ESCAPE, "");

  // copy yellow escape to the variable
  strncpy(HOLD_ESCAPE, BOLD_YEL_NON, MAX_ESCAPE_LENGTH);

  // print the loglist header
  printf(" %s%s:%s\n"
         "\n"         ,
         HOLD_ESCAPE  ,
         self -> title,
         NONE_NON_NON );

  // if the LogList is empty (It's an unexpectedly behavior, even no
  // Logs appended)
  if (self -> linked_logs == NULL)
    printf("   This LogList is unexpectedly empty :(\n");

  // if linked_logs equals to NULL, nothing will hapen. This is a
  // safe function call ;^)
  display_log(self -> linked_logs);
}

/* Function: display_log
 * ---------------------
 *  This function receive 1 argument:
 *    - self: Log struct pointer
 *
 *  The purpose of this function is just print the Log struct
 *  contents in a pretty way
 * --------------------------------------------------------------- */
void display_log(struct Log *self) {

  // if given pointer is invalid (NULL)
  if (self == NULL)
    return; // return

  // getting the current log struct pointer
  struct Log *current_log = self;

  // while this pointer is not null (is equals to a define Log
  // struct)
  while (current_log != NULL) {

    // print the STATUS MARK
    printf("  > ");

    // clear HOLD_ESCAPE variable
    strcpy(HOLD_ESCAPE, "");

    // switch case by Log struct Status
    //    - will update the STATUS_TEXT according to the status
    //    - will updated the HOLD_ESCAPE according to the status
    switch (current_log -> status) {

      // if status is OK
      case OK:
        strncpy(STATUS_TEXT, "OK"        , STATUS_TEXT_LENGTH);
        strncpy(HOLD_ESCAPE, NONE_GRE_NON, MAX_ESCAPE_LENGTH );
        break;

      // if status is FAIL
      case FAIL:
        strncpy(STATUS_TEXT, "FAIL"      , STATUS_TEXT_LENGTH);
        strncpy(HOLD_ESCAPE, NONE_RED_NON, MAX_ESCAPE_LENGTH );
        break;

      // if status is WARNING
      case WARNING:
        strncpy(STATUS_TEXT, "WARNING"   , STATUS_TEXT_LENGTH);
        strncpy(HOLD_ESCAPE, NONE_MAG_NON, MAX_ESCAPE_LENGTH );
        break;

      // if status is other type (NONE maybe)
      default:
        strncpy(STATUS_TEXT, "MESSAGE"   , STATUS_TEXT_LENGTH);
        strncpy(HOLD_ESCAPE, NONE_BLU_NON, MAX_ESCAPE_LENGTH );
        break;
    }

    // printing content
    printf("%s%s:%s\n" ,  // header by getting:
           HOLD_ESCAPE ,  //   - status color escape
           STATUS_TEXT ,  //   - status text value
           NONE_NON_NON); //   - escape reset

    // while the message current line isn't equals to NULL (content
    // end)
    for (int i = 0; current_log -> message[i] != NULL; i++)
      printf("    %s\n"               ,
             current_log -> message[i]); // print that line

    // break one line to the next Log struct
    printf("\n");

    // update current log pointer to the next one
    current_log = current_log -> next_log;
  }
}
