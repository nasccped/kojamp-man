#ifndef _LOG_H_ // if log.h isn't already define
#define _LOG_H_ // defien it

// stdbool.h contents will be necessary, so:
#ifndef _STDBOOL_H_    // if stbool.h isn't already defined
  #include <stdbool.h> // include it
#endif


// main function at log.c (it will generate all Log related
// constants)
void log_main(void);

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
enum Status {
  OK     ,
  FAIL   ,
  WARNING,
  NONE
};

/* Struct: Log (consider also some kind of linked list)
 * ----------------------------------------------------
 *  This struct store 3 values:
 *    - status  : Status enum
 *    - message : char pointer pointer (array of strings)
 *    - next_log: pointer to the next Log struct
 *
 *  The purpose of Log struct is to store some diagnosis on a
 *  variable. It will store the diagnosis status (depend on the
 *  diagnosis situation) and the diagnosis description.
 *
 *  The message variable (diagnosis description) is a string array
 *  (char **) with an NULL value at last (end of description marker),
 *  so, you might consider as a group of rows:
 *
 *    char **message = {"This is row 1,"    ,
 *                      "And this is row 2!",
 *                      "Looks cool, naw?"  ,
 *                      NULL                };
 *
 *    Equals to:
 *
 *    This is row 1,
 *    And this is row 2!
 *    Looks cool, naw?
 *
 *  The next_log value will point to the next log in our list, so we
 *  can get the current Log pointer, read values and go to the next
 *  Log pointer without putting them all in a malloc'ed array (avoid
 *  malloc, realloc and free. Avoid also memory errors/overflow)
 * --------------------------------------------------------------- */
struct Log {
  enum Status  status  ;
  char       **message ;
  struct Log  *next_log;
};

/* Struct: LogList
 * ---------------
 *  This struct store 2 values:
 *    - title      : char pointer (aka string)
 *    - linked_logs: Log struct pointer
 *  -----------------------------------------------------------------
 *  The title value will store the title of current LogList
 *
 *  The linked_logs will store the pointer to the first Log struct.
 *  The data of this pointer can be read and we can go to the next
 *  one since Log Struct hold a pointer to another Log
 * --------------------------------------------------------------- */
struct LogList {
  char       *title      ;
  struct Log *linked_logs;
};

// max length that STATUS_TEXT can store (constant) -----------------
#define STATUS_TEXT_LENGTH  15

// generate LogList structs that will be used by the program
static struct LogList ENV_CHECKER_LOGLIST = {"Environment Checker",
                                             NULL                 };

// functions declaration --------------------------------------------
void append_log     (struct LogList *self, struct Log *new_log);
void display_log    (struct Log     *self)                     ;
void display_loglist(struct LogList *self)                     ;

// exporting our variables ------------------------------------------
extern struct Log LOGLIST_IS_EMPTY;
static char      *LOG_IS_EMP_STR[] = {"This LogList is empty.",
                                       "Everything is OK ^u^" ,
                                       NULL                   };

extern struct Log BIN_DIR_IS_NULL;
static char      *BIN_DIR_IS_NLL_STR[] = {"Binary path with `getcwd()` function could not be",
                                          "set. NULL value was returned"                     ,
                                          NULL                                               };

extern char STATUS_TEXT[STATUS_TEXT_LENGTH];

#endif
