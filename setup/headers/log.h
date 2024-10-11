#ifndef _LOG_H_ // if log.h isn't already define
#define _LOG_H_ // defien it

// stdbool.h contents will be necessary, so:
#ifndef _STDBOOL_H_    // if stbool.h isn't already defined
  #include <stdbool.h> // include it
#endif

// max length that STATUS_TEXT can store
#define STATUS_TEXT_LENGTH 15

// our enums and structs --------------------------------------------

/* Enum: Status
 * ------------
 *  This enum store 4 different constants:
 *    - OK
 *    - FAIL
 *    - WARNING
 *    - NONE
 *
 *  Alone, these constants doesn't matter so much, buch it can be
 *  used at the Log struct (mentioned bellow)
 * --------------------------------------------------------------- */
typedef enum {
  OK     ,
  FAIL   ,
  WARNING,
  NONE
} Status;

/* Struct: Log
 * -----------
 *  This struct store 2 variables:
 *    - status : Status enum
 *    - message: char pointer
 *
 *  The purpose of Log struct is to store some diagnosis on a
 *  variable. It will store the diagnosis status (depend on the
 *  diagnosis situation) and the diagnosis description.
 * --------------------------------------------------------------- */
typedef struct {
  Status status ;
  char  *message;
} Log;

/* Struct: LogList
 * ---------------
 *  This struct store 4 values:
 *    - title     : char pointer
 *    - array     : array of Log pointers (Log **)
 *    - length    : int
 *    - append_log: function pointer
 *  -----------------------------------------------------------------
 *  The title variable will store the title of current LogList
 *
 *  The array variable will store all the Logs related to this
 *  LogList
 *
 *  The length variable will store the elements amount within the
 *  array
 *
 *  The append_log variable will store the pointer to the
 *  append_log function. This function can add Log pointer to the
 *  LogList array by receiving some valid arguments
 * --------------------------------------------------------------- */
struct LogList {
  char *title  ;
  Log  **array ;
  int    length;
  void (* append_log)(struct LogList *self,
                      Status   status  ,
                      char    *message);
};

// functions declaration --------------------------------------------
void append_log(struct LogList *self, Status status, char *message);
void free_loglist(struct LogList *self, bool error_occurs)         ;
void display_log(Log *self)                                        ;
void display_loglist(struct LogList *self)                         ;

// exporting our variables ------------------------------------------
extern char STATUS_TEXT[STATUS_TEXT_LENGTH];

#endif
