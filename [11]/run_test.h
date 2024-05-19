#include <stdlib.h>
#include <stdio.h>

void run_test(int no, int result, int expected_result){
  printf("No.%2d: ", no);
  if ( result == expected_result ){
    printf("PASS\n");
  }
  else{
    printf("*** FAIL! ***: result = %d (expected result = %d)\n", result, expected_result);
    exit(1);
  }
}
