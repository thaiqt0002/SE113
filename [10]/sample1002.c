#include <stdio.h>
#include <string.h>

int myProgram(void) {
  int inputOption, decimalNumber, convertedNumber, index;
  int binaryArray[16];
  char binaryString[17];

  printf("[radix conversion]\n");
  printf(" 1) Dec --> Bin\n");
  printf(" 2) Bin --> Dec\n");
  printf("\n");
  printf("Select 1 or 2\n> ");
  scanf("%d", &inputOption);

  if (inputOption == 1) {
    printf("\n 1) Dec --> Bin\n\n");
    printf("Input decimal number\n> ");
    scanf("%d", &decimalNumber);
    if (decimalNumber < 0 || decimalNumber > 65535) {
      printf("[ERROR] invalid decimal number\n");
      return 1;
    }

    printf("Convert it to binary number\n\n");
    index = 0;
    convertedNumber = decimalNumber;
    do {
      binaryArray[index] = convertedNumber % 2;
      convertedNumber /= 2;
      index++;
    } while (convertedNumber > 0);

    printf(" %d --> ", decimalNumber);
    do {
      index--;
      printf("%d", binaryArray[index]);
    } while (index > 0);
    printf("\n");
  } else if (inputOption == 2) {
    printf("\n 2) Bin --> Dec\n\n");
    printf("Input binary number\n> ");
    scanf("%s", binaryString);
    if ((int)strlen(binaryString) > 16) {
      printf("[ERROR] too long binary number\n");
      return 1;
    }

    printf("Convert it to decimal number\n\n");
    convertedNumber = 0;
    for (index = 0; index < (int)strlen(binaryString); index++) {
      convertedNumber *= 2;
      if (binaryString[index] == '1') {
        convertedNumber += 1;
      } else if (binaryString[index] == '0') {
        convertedNumber += 0;
      } else {
        printf("[ERROR] invalid binary number\n");
        return 1;
      }
    }

    printf(" %s --> %d\n", binaryString, convertedNumber);
  } else {
    printf("[ERROR] invalid number\n");
    return 1;
  }

  return 0;
}

int main(void) {
  return myProgram();
}