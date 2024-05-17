#include <stdio.h>

int main(void)
{
  int side[3], i, j, tmp, max_p;

  printf("Input three sides:\n> ");
  scanf("%d %d %d", &side[0], &side[1], &side[2]);

  /* sort three sides in descending order */
  for (i = 0; i < 3; i++)
  {
    max_p = i;
    for (j = i + 1; j < 3; j++)
    {
      if (side[max_p] < side[j])
      {
        max_p = j;
      }
    }
    tmp = side[max_p];
    side[max_p] = side[i];
    side[i] = tmp;
  }

  printf("\n");
  printf("three sides =");
  for (i = 0; i < 3; i++)
  {
    printf(" %d", side[i]);
  }
  printf("\n");

  printf(" ===> ");
  if (side[0] >= 100 || side[2] < 1)
  {
    printf("[ERROR]\n");
    return 0;
  }
  if (side[0] < side[1] + side[2])
  {
    if (side[0] == side[1] && side[1] == side[2])
    {
      printf("equilateral triangle\n");
      return 0;
    }
    else if (side[0] == side[1] || side[1] == side[2])
    {
      printf("isosceles triangle\n");
      return 0;
    }
    else
    {
      printf("scalene triangle\n");
      return 0;
    }
  }
  printf("[ERROR] not a triangle\n");

  return 0;
}
