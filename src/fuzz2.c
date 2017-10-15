#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <stdio.h>

#include "func2.h"

void Fuzz_int_pair_to_str(const uint8_t *data, size_t data_size) {
//  printf("%s called with %d bytes\n", __func__, (int)data_size);

  int pair[2];
  if (data_size < sizeof(pair))
  {
    return;
  }

  const size_t MAX_STR_LEN=255;
  char str[MAX_STR_LEN];

  memcpy(&(pair[0]), data, sizeof(pair));
  int_pair_to_str(pair[0], pair[1], str, MAX_STR_LEN);
}

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  Fuzz_int_pair_to_str(Data, Size);
  return 0;
}
