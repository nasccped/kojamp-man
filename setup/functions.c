#ifndef _FUNCTIONS_H_
  #include "headers/functions.h"
#endif

// string lib will be necessary, so
#ifndef _STRING_H_
  #include <string.h>
#endif

/* Function: find_char_on_array
 * ----------------------------
 *  The function name is self explanatory. It will return a boolean
 *  by taking three arguments:
 *    - searching   : char pointer, aka string
 *    - target_array: const char pointer of pointers (string array)
 *    - array_length: int
 *
 *  Basically, we'll gonna test if an specific string is in a string
 *  array. If the searched string is null (also, if the array is null
 *  too), return false (We can't search for NULL pointers when string
 *  is expected).
 *
 * If everything is OK, then we gonna iterate through the strings
 * array by taking the `array_length` as a range. If the current
 * element in the iter is the same as the searched one, return true,
 * else, go to the next element.
 *
 * If the searched element wasn't founded, return false
 * --------------------------------------------------------------- */
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
