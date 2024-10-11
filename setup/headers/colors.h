#ifndef _COLORS_H_ // if colors.h isn't already defined
#define _COLORS_H_ // define it

// defining the max lenght of color escape
#define MAX_ESCAPE_LENGTH 30

// our escapes constants --------------------------------------------
//    all variable is builded by the following rule:
//      `static const char A_B_C[D] = "E";`
//
//    where:
//      A -> font style (bold, italicized, underline, none, etc)
//      B -> font foreground color
//      C -> font background color
//      D -> char[] size, defined by the `MAX_ESCAPE_LENGTH` variable
//      E -> escape itself
//    ---------------------------------------------------------------
//      A will be write only with 4 letters
//      B and C, 3
static const char NONE_NON_NON[MAX_ESCAPE_LENGTH] = "\033[0m"   ;
static const char NONE_RED_NON[MAX_ESCAPE_LENGTH] = "\033[31m"  ;
static const char NONE_GRE_NON[MAX_ESCAPE_LENGTH] = "\033[32m"  ;
static const char NONE_YEL_NON[MAX_ESCAPE_LENGTH] = "\033[33m"  ;
static const char NONE_BLU_NON[MAX_ESCAPE_LENGTH] = "\033[34m"  ;
static const char NONE_MAG_NON[MAX_ESCAPE_LENGTH] = "\033[35m"  ;
static const char BOLD_RED_NON[MAX_ESCAPE_LENGTH] = "\033[1;31m";
static const char BOLD_GRE_NON[MAX_ESCAPE_LENGTH] = "\033[1;32m";
static const char BOLD_YEL_NON[MAX_ESCAPE_LENGTH] = "\033[1;33m";

// extern variables -------------------------------------------------
extern char HOLD_ESCAPE[MAX_ESCAPE_LENGTH];

#endif
