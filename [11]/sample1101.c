#include "run_test.h"
#define ERROR -1
int get_digit_number(int x) {
  if (x > 0 && x < 1000000) {
    return x/5 ;
  } else {
    return -1;
  }
}

int main(void) {

  run_test(1, get_digit_number(5), 1);
  run_test(2, get_digit_number(10), 2);
  run_test(3, get_digit_number(500), 100);
  run_test(4, get_digit_number(1000000), -1);
  run_test(5, get_digit_number(0), 0);
  return 0;
}
