#include <stdio.h>
#include <string.h>

#define MAX_BINARY_LENGTH 16
#define MAX_BINARY_STRING_SIZE 17
#define MAX_INTEGER_VALUE 65535

int main(void) {
  int input_option, decimal_number, converted_number, index;
  int binary_array[MAX_BINARY_LENGTH];
  char binary_string[MAX_BINARY_STRING_SIZE];

  printf("[radix conversion]\n");
  printf(" 1) Dec --> Bin\n");
  printf(" 2) Bin --> Dec\n");
  printf("\n");
  printf("Select 1 or 2\n> ");
  scanf("%d", &input_option);

  if (input_option == 1) {
    printf("\n 1) Dec --> Bin\n\n");
    printf("Input decimal number\n> ");
    scanf("%d", &decimal_number);
    if (decimal_number < 0 || decimal_number > MAX_INTEGER_VALUE) {
      printf("[ERROR] invalid decimal number\n");
      return 1;
    }

    printf("Convert it to binary number\n\n");
    index = 0;
    converted_number = decimal_number;
    do {
      binary_array[index] = converted_number % 2;
      converted_number /= 2;
      index++;
    } while (converted_number > 0);

    printf(" %d --> ", decimal_number);
    do {
      index--;
      printf("%d", binary_array[index]);
    } while (index > 0);
    printf("\n");
  } else if (input_option == 2) {
    printf("\n 2) Bin --> Dec\n\n");
    printf("Input binary number\n> ");
    scanf("%s", binary_string);
    if ((int)strlen(binary_string) > MAX_BINARY_LENGTH) {
      printf("[ERROR] too long binary number\n");
      return 1;
    }

    printf("Convert it to decimal number\n\n");
    converted_number = 0;
    for (index = 0; index < (int)strlen(binary_string); index++) {
      converted_number *= 2;
      if (binary_string[index] == '1') {
        converted_number += 1;
      } else if (binary_string[index] == '0') {
        converted_number += 0;
      } else {
        printf("[ERROR] invalid binary number\n");
        return 1;
      }
    }

    printf(" %s --> %d\n", binary_string, converted_number);
  } else {
    printf("[ERROR] invalid number\n");
    return 1;
  }

  return 0;
}