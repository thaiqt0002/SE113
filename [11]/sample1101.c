#include "run_test.h"

#define ERROR -1

int get_digit_number(int x) {
  if (x <= 0 || x >= 1000000) {
    return ERROR;
  }

  int digits = 0;
  while (x != 0) {
    x /= 10;
    ++digits;
  }

  return digits;
}

int main(void) {
  run_test(1, get_digit_number(5), 1);
  run_test(2, get_digit_number(256), 3);
  run_test(3, get_digit_number(0), -1);
  run_test(4, get_digit_number(999999), 6);
  run_test(5, get_digit_number(1000000), -1);
  return 0;
}
