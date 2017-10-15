#include <stdio.h>
#include <stdlib.h>

#include "func2.h"
 
int main()
{
  printf("Hello, size of  int=%lu\n", sizeof(int));
  //  printf("Hello World\n");

//    basic_bad_srand_lines();
//  uipair_bad_srand_lines();
  const size_t MAX_SIZE_STR=200;
  char str[MAX_SIZE_STR];

  int_pair_to_str(2,20,str, MAX_SIZE_STR);
  printf("Str is \"%s\"\n", str);

  int_pair_to_str(44, 52,str, MAX_SIZE_STR);
  printf("Str is \"%s\"\n", str);

  int_pair_to_str(51, 10,str, MAX_SIZE_STR);
  printf("Str is \"%s\"\n", str);

  int_pair_to_str(52, 620,str, MAX_SIZE_STR);
  printf("Str is \"%s\"\n", str);


  return 0;
}
