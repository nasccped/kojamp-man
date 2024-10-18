#ifndef _FUNCTIONS_H_
  #include "headers/functions.h"
#endif

#ifndef _STRING_H_
  #include <string.h>
#endif

bool find_char_on_array(char        *searching   ,
                        const char **target_array,
                        int          array_length) {

  if (searching == NULL || target_array == NULL)
    return false;

  for (int i = 0; i < array_length; i++)
    if (strcmp(searching, target_array[i]) == 0)
      return true;

  return false;
}
