#include "homework_run_test.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ERROR -1

float roundScore(float num) { return round(2. * num) / 2.; }

float average(int lab, float score[], int late[]) {
  int temp_late = 0;
  for (int i = 0; i < lab; ++i) {
    if (late[i] == 1) {
      ++temp_late;
      switch (temp_late) {
      case 1:
      case 2: {
        score[i] *= 0.9;
        break;
      }
      case 3: {
        score[i] *= 0.7;
        break;
      }
      default:
        score[i] = 0;
        break;
      }
    }
  }
  float sum = 0;
  for (int i = 0; i < lab; ++i) {
    sum += score[i];
  }
  float avg = sum / lab;
  return avg;
}

float calculatePracticeScore(int lab, float lab_score[], int late[],
                             int attendance) {
  if (lab <= 0 || lab > 5) {
    return ERROR;
  }
  if (attendance > 15 || attendance < 0) {
    return ERROR;
  }
  for (int i = 0; i < lab; ++i) {
    if (lab_score[i] < 0 || lab_score[i] > 10 ||
        (late[i] != 0 && late[i] != 1)) {
      return ERROR;
    }
  }
  float avg = average(lab, lab_score, late);
  if (avg > 5 && attendance < 10) {
    avg = avg * 0.9;
  }
  avg = roundScore(avg);
  return avg;
}

int main() {
  homework_run_test(1, calculatePracticeScore(4, (float[]){6, 7, 8.5, 9}, (int[]){0, 0, 0, 0}, 13), 7.5);
  homework_run_test(2, calculatePracticeScore(6, (float[]){6, 7, 8.5, 9}, (int[]){0, 0, 0, 0}, 9), ERROR);
  homework_run_test(3, calculatePracticeScore(3, (float[]){4,5,6}, (int[]){0, 0, 0}, 11), 5);
  homework_run_test(4, calculatePracticeScore(5, (float[]){4,5,6,7,8}, (int[]){0, 0, 1, 0, 1}, 9), 5);
  homework_run_test(5, calculatePracticeScore(3, (float[]){8,9,11}, (int[]){0, 0, 1}, 10), ERROR);
  homework_run_test(6, calculatePracticeScore(3, (float[]){8,9,-1}, (int[]){1, 1, 1}, 9), ERROR);
  homework_run_test(7, calculatePracticeScore(3, (float[]){8,9,10}, (int[]){2, 0, 0}, 10), ERROR);
  homework_run_test(8, calculatePracticeScore(4, (float[]){5,8,9,10}, (int[]){1,0, 0, 0}, 5), 7);
  homework_run_test(9, calculatePracticeScore(4, (float[]){1,2,3,4}, (int[]){1,0, 0, 0}, 10), 2.5);
  homework_run_test(10, calculatePracticeScore(4, (float[]){1,2,3,4}, (int[]){1,0, 0, 0}, 16), ERROR);
  homework_run_test(11, calculatePracticeScore(4, (float[]){1,2,3,4}, (int[]){1,0, 0, 0}, -1), ERROR);
  homework_run_test(12, calculatePracticeScore(5, (float[]){5,6,7,8}, (int[]){1,0, 0, 1}, 1), ERROR);
  homework_run_test(13, calculatePracticeScore(5, (float[]){5,6,7,8,9}, (int[]){1,1,0, 0, 1}, 0), 5.5);
  homework_run_test(14, calculatePracticeScore(1, (float[]){1}, (int[]){1}, 15), 1);
  homework_run_test(15, calculatePracticeScore(0, (float[]){1}, (int[]){1}, 15), ERROR);
  homework_run_test(16, calculatePracticeScore(4, (float[]){1,2,3,4}, (int[]){0,0,0,0}, 15), 2.5);
  homework_run_test(17, calculatePracticeScore(4, (float[]){6,5,7,4}, (int[]){0,0,0,0}, 9), 5);
  homework_run_test(18, calculatePracticeScore(5, (float[]){1,2,3,4,5}, (int[]){0,0,0,0}, 10), ERROR);
  return 0;
}