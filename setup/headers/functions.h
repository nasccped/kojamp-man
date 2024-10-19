#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

// stdbool lib will be necessary
#ifndef _STDBOOL_H_
  #include <stdbool.h>
#endif

// functions declaration (function description at functions.c) ------
bool find_char_on_array(char        *searching   ,
                        const char **target_array,
                        int          array_length);

#endif
