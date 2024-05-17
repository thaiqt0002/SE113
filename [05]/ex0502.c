#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
  int inputInt = 0;
  printf("n = ");
  scanf("%d", &inputInt);
  if (!(0 < inputInt && inputInt < 10))
  {
    printf("ERROR: invalid number of students (%d)\n", inputInt);
    return 1;
  }
  int studentsScores[inputInt], maxScore = 0, minScore = 100, passedStudents = 0, evaluatedStudents = 0;
  double averageScore = 0;
  printf("scores = ");
  for (int i = 0; i < inputInt; ++i)
  {
    scanf("%d", &studentsScores[i]);
  }
  for (int i = 0; i < inputInt; ++i)
  {
    int currentScore = studentsScores[i];
    if (!(-1 <= currentScore && currentScore <= 100))
    {
      printf("ERROR: invalid score (%d)\n", currentScore);
      return 1;
    }
    if (currentScore == -1)
    {
      continue;
      ;
    }
    if (currentScore >= 60)
    {
      ++passedStudents;
    }
    ++evaluatedStudents;
    averageScore = floor(((averageScore * (evaluatedStudents - 1) + currentScore) / evaluatedStudents) * 10) / 10;
    maxScore = maxScore < currentScore ? currentScore : maxScore;
    minScore = minScore > currentScore ? currentScore : minScore;
  }
  printf("======= score info =======\n#students = %d\n#passed = %d (%.1f%%)\n\nave = %.1f max = %d min = %d", inputInt, passedStudents, floor(((float)passedStudents / inputInt * 100) * 10) / 10, averageScore, maxScore, minScore);
  return 0;
}