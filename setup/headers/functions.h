#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

#ifndef _STDBOOL_H_
  #include <stdbool.h>
#endif

bool find_char_on_array(char        *searching   ,
                        const char **target_array,
                        int          array_length);

#endif
