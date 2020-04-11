#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergeTimed.h"

int main(int argc, char *argv[])
{
  srand(time(NULL));
  double time_spent = 0.0;
  double average_time;

  printf("|   n   |  t1  |  t2  |  t3  |  t4  |  t5  | avrg |\n");
  printf("===================================================\n");

  for (int i = 10000; i <= 100000; i += 10000)
  {
    average_time = 0.0;
    if (i == 100000)
    {
      printf("|%d |", i);
    }
    else
    {
      printf("| %d |", i);
    }

    for (int j = 0; j < 5; j++)
    {
      clock_t start = clock();
      readFile(i);
      clock_t stop = clock();

      time_spent += (double)(stop - start) / CLOCKS_PER_SEC;
      average_time += time_spent;
      if (time_spent > 10)
      {
        printf("%.2f |", time_spent);
      }
      else
      {
        printf(" %.2f |", time_spent);
      }
    }

    average_time = average_time / 5;
    if (average_time > 10)
    {
      printf("%.2f |\n", average_time);
    }
    else
    {
      printf(" %.2f |\n", average_time);
    }
  }

  return 0;
};