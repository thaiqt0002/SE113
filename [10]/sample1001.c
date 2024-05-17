#include <stdio.h>
#define X 10

int findMinIndex(int arr[], int start, int end) {
  int minIndex;
  int i;
  minIndex = start;
  for (i = start + 1; i <= end; i++) {
    if (arr[i] < arr[minIndex])
      minIndex = i;
  }
  return minIndex;
}

void selectionSort(int arr[], int size) {
  int i, j, temp;
  for (i = 0; i < size; i++) {
    j = findMinIndex(arr, i, size - 1);
    if (j != i) {
      temp = arr[j];
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
}

int main(void) {
  int i, n, arr[X];
  scanf("%d", &n);
  if (n <= 0) {
    printf("[ERROR] data count must be positive!\n");
    return 1;
  }
  if (n > X) {
    printf("[ERROR] too many data!\n");
    return 1;
  }
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printf("before: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  selectionSort(arr, n);
  printf("after:  ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
