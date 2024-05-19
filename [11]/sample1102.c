#include <stdio.h>
#include "run_test.h"

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

  int totalAmount;
  if (sale == 1) {
    totalAmount = order * 90 / 100; 
  } else if (sale == 2) {
    totalAmount = order * 70 / 100;
  } else {
    totalAmount = order;
  }

  // Calculate the delivery charge
  int deliveryCharge;
  if (member == 0 && totalAmount < 2000) {
    deliveryCharge = 410;
  } else {
    deliveryCharge = 0;
  }

  // Calculate the billing amount
  int billingAmount = totalAmount + deliveryCharge;

  return billingAmount;
}

int main(void) {
  run_test(1, charge(1100, 1, 0), 1100);
  run_test(2, charge(0, 0, 0), -1);
  run_test(3, charge(2178, 0, 2), 1934);

  return 0;
}
