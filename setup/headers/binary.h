#ifndef _BINARY_H_
#define _BINARY_H_

// binary.c 'main' function declaration
void binary(void);


// consts to store 'cmd  values'
static const char *BINARY_CMD_EXPECTED[]   = {"--binary", "-B"};
static const int   BINARY_CMD_EXPECTED_LEN = (
  sizeof(BINARY_CMD_EXPECTED) / sizeof(BINARY_CMD_EXPECTED[0]));

#endif
