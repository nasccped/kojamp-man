#ifndef __INCLUDE__H_
  #include "headers/_include_.h"
#endif


int main(int argc, char *argv[]) {

  printf("Arguments count: %d\n", argc - 1);

  for (int i = 1; i < argc; i++)
    printf("  %s\n", argv[i]);

  return 0;
}
