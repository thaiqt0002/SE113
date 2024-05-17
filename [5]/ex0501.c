#include <stdio.h>

int main(void){
  int time, amount, sale, discount, bill, t;

  printf("Input the parking time (min): ");
  scanf("%d", &time);
  if ( time < 0 ){
    printf("[ERROR] invalid input\n");
    return 1;
  }

  printf("Input the purchased amount at parter shops (yen): ");
  scanf("%d", &sale);
  if ( sale < 0 ){
    printf("[ERROR] invalid input\n");
    return 1;
  }


  amount = 100;
  if ( time > 30 && time < 60 ){
    amount = 200;
  }
  else{
    t = time - 60;
    while ( t > 0 ){
      amount += 100;
      t -= 60;
    }
  }

  discount = 0;
  if ( sale > 2000 ){
    discount = 200;
  }

  bill = amount - discount;
  if ( bill < 0 ){
    bill = 0;
  }

  printf("\n");
  printf("======= parking fee =======\n\n");

  printf(" (a) time: %d mins\n", time);
  printf("       ==> %d yen\n\n", amount);

  printf(" (b) purchase: %d yen\n", sale);
  printf("       ==> discount %d yen\n\n", discount);

  printf("---------------------------\n");
  printf(" (*) total: %d yen\n", bill);
  printf("===========================\n");

  return 0;
}
