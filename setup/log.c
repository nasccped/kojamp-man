// our includes
#include "headers/_include_.h" // _include_.h
#include "headers/log.h"       // log.h
#include "headers/colors.h"    // colors.h

// variable call ----------------------------------------------------
char HOLD_ESCAPE[MAX_ESCAPE_LENGTH ];
char STATUS_TEXT[STATUS_TEXT_LENGTH];

/* Function: append_log
 * --------------------
 *  This function receive 3 arguments:
 *    - self   :   LogList struct pointer
 *    - status :   Status enum value
 *    - message:   String (char pointer) content
 *
 *  It will take the self pointer and test if it's a valid pointer
 *  (not equals NULL). If true, the function will generate a Log
 *  struct pointer by malloc function, insert status and message on
 *  it. Then, will increase `sizeof` LogList array pointer by using
 *  realloc and finally append the created Log pointer to the array
 *
 *  This function doesn't return nothing, just update the LogList
 *  values by getting the variable address
 *
 *  If some unexpected behaviour occurs (like memory error
 *  allocation) all the LogList pointer content (array and his
 *  elements) will be free'd and LogList length will be updated to -1
 *
 *  In this case, the function will stop immediately by the return
 *  keyword
 * --------------------------------------------------------------- */
void append_log(struct LogList *self,
                Status   status     ,
                char    *message    ) {

  // if LogList addres is invalid
  if (self == NULL || self -> array == NULL)
    return; // return function

  // if LogList array is invalid
  if (self -> array == NULL) {
    self -> length = -1; // update lenth to warn error
    return             ; // return function
  }

  // storing array in a temporary pointer
  Log **temp_logs = self -> array;

  // doing memory reallocation by adding 1 Log pointer
  temp_logs = realloc(temp_logs, sizeof(self -> array) + sizeof(Log *));

  // if reallocation fails
  if (temp_logs == NULL) {
    free_loglist(self, true); // free the LogList pointers
    return                  ; // return function
  }

  // update in the LogList addred:
  self -> array = temp_logs; // old array pointer -> new realloc'ed array
  self -> length++         ; // lenght incremented by 1

  // create a new pointer (will be added to list)
  Log *current_log = (Log *)malloc(sizeof(Log *));

  // if the pointer is invalid
  if (current_log == NULL) {
    free_loglist(self, true); // free the LogList pointers
    return                  ; // return function
  }

  // update on the new created pointer
  current_log -> status  = status ; // the Status enum
  current_log -> message = message; // the message String

  // define the target index
  int insert_at = self -> length - 1;

  // insert on it
  self -> array[insert_at] = current_log;
}

/* Function: free_loglist
 * ----------------------
 *  This function receive:
 *    - self        : LogList struct pointer
 *    - error_occurs: boolean (bool)
 *
 *  It will take the self pointer and do some tests (if it's valid).
 *  Then, if everything is OK, will free each pointer from the
 *  LogList array and the array itself
 * --------------------------------------------------------------- */
void free_loglist(struct LogList *self, bool error_occurs) {

  // if the given pointer is invalid
  if (self == NULL)
    return; // return function

  // if array pointer is already null
  if (self -> array == NULL) {
    self -> length = -1; // update the length
    return             ; // return function
  }

  // for each element of the array
  for (int i = 0; i < self -> length; i++)
    free(self -> array[i]); // free it

  // free the array itself
  free(self -> array);

  // lenght update (-1 if error occcurs | 0 if not error)
  self -> length = (error_occurs) ? -1 : 0;
}

/* Function: display_loglist
 * -------------------------
 *  This function receive just one argument:
 *    - self: LogList struct pointer
 *
 *  The purpose of this function is only display each element
 *  allocated on the array, so... if the self pointer even array
 *  pointer equals NULL, the function will be terminated (return)
 *
 *  Otherwise, the function will print the Log's status and messages
 *  by a for lop
 * --------------------------------------------------------------- */
void display_loglist(struct LogList *self) {

  // if invalid pointers
  if (self == NULL || self -> array == NULL)
    return; // return

  // clear HOLD_ESCAPE
  strcpy(HOLD_ESCAPE, "");

  // copy yellow escape to the variable
  strncpy(HOLD_ESCAPE, BOLD_YEL_NON, MAX_ESCAPE_LENGTH);

  // print the loglist header
  printf("|> %s%s:%s\n"
         "|\n"         ,
         HOLD_ESCAPE   ,
         self -> title ,
         NONE_NON_NON  );

  // for each Log struct on the array
  for (int i = 0; i < self -> length; i++) {

    // print the STATUS MARK
    printf("|--- ");

    // call other function to print the content
    display_log(self -> array[i]);

    // break line
    printf("|\n");
  }
}

/* Function: display_log
 * ---------------------
 *  This function receive one argument:
 *    - self: Log struct pointer
 *
 *  The purpose of this function is just print the Log struct
 *  contents in a pretty way
 * --------------------------------------------------------------- */
void display_log(Log *self) {

  // if given pointer is invalid (NULL)
  if (self == NULL)
    return; // return

  // clear HOLD_ESCAPE variable
  strcpy(HOLD_ESCAPE, "");

  // switch case by Log struct Status
  //    - will update the STATUS_TEXT according to the status
  //    - will updated the HOLD_ESCAPE according to the status
  switch (self -> status) {

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

  // message
  printf("|\t%s\n", self -> message);
}
