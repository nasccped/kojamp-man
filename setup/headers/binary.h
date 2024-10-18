#ifndef _BINARY_H_
#define _BINARY_H_

void binary(void);


static const char *BINARY_CMD_EXPECTED[]   = {"--binary", "-B"};
static const int   BINARY_CMD_EXPECTED_LEN = (
  sizeof(BINARY_CMD_EXPECTED) / sizeof(BINARY_CMD_EXPECTED[0]));

#endif
