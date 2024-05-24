#include <stdio.h>
#include <stdlib.h>

int find_max(int a[], int n){
  int max = 0;
  int i;
  for ( i = 1; i < n; i++ ){
    if ( a[i] > a[max] ){
      max = i;
    }
  }

  return max;
}

void selection_sort(int a[], int n){
  int i, tmp, max;

  for( i = 0; i < n-1; i++ ){
    max = find_max(a, n-i);
    tmp = a[max];
    a[max] = a[n-1-i];
    a[n-1-i] = tmp;
  }
}

int main(int argc, char* argv[]){
  int N = atoi(argv[1]);
  int i;
  int* a = (int*)calloc(N, sizeof(int));
  int n;

  for( i = 0; i < N; i++ ){
    a[i] = N - i;
  }

  printf("before: ");
  for ( i = 0; i < N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");

  selection_sort(a,N);

  printf("after: ");
  for ( i = 0; i < N; i++ ){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
