#include "run_test.h"
#include <stdio.h>

int charge(int order, int member, int sale) {

  if (order <= 0 || order >= 1000000) {
    return -1;
  }

  if (member != 0 && member != 1) {
    return -1;
  }

  if (sale != 0 && sale != 1 && sale != 2) {
    return -1;
  }

  if (sale == 1) {
    order = order * 90 / 100;
  } else if (sale == 2) {
    order = order * 70 / 100;
  }

  // Calculate the delivery charge
  int deliveryCharge = 0;
  if (member == 0 && order < 2000) {
    deliveryCharge = 410;
  }

  // Calculate the billing amount
  int billingAmount = order + deliveryCharge;

  return billingAmount;
}

int main(void) {
  run_test(1, charge(1100, 1, 0), 1100);
  run_test(2, charge(0, 0, 0), -1);
  run_test(3, charge(2178, 0, 2), 1934);

  return 0;
}
