#include <stdio.h>
#include <stdlib.h>

void homework_run_test(int no, float result, float expected_result) {
  printf("No.%2d: ", no);
  if (result == expected_result) {
    printf("PASS\n");
  } else {
    printf("*** FAIL! ***: result = %f (expected result = %f)\n", result, expected_result);
  }
}

// Path: homework_run_test.h
