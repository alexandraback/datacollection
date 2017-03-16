#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 4

int main (int carg, char* args[])
{
  // read and populate data
  int trials;
  int first[ROWS][COLS];
  int second[ROWS][COLS];

  int first_row;
  int second_row;

  int matches;
  int choice;

  fscanf(stdin, "%d", &trials);
  for (int t = 0; t < trials; t++)
  {
    fscanf(stdin, "%d", &first_row);
    for (int i = 0; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        fscanf(stdin, "%d", &(first[i][j]));
      }
    }

    fscanf(stdin, "%d", &second_row);
    for (int i = 0; i < ROWS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        fscanf(stdin, "%d", &(second[i][j]));
      }
    }

    --first_row;
    --second_row;

    matches = 0;
    choice = -1;
    int poss[COLS];
    memcpy (poss, first[first_row], COLS * sizeof(int));
    for (int i = 0; i < COLS; i++)
    {
      for (int j = 0; j < COLS; j++)
      {
        if (poss[i] == second[second_row][j])
        {
          ++matches;
          choice = poss[i];
        }
      }
    }

    char* out_string = malloc(50 * sizeof(char));;
    if (matches)
    {
      if (matches == 1)
      {
        sprintf(out_string, "%d", choice);
      }
      else
      {
        sprintf(out_string, "Bad magician!");
      }
    }
    else
    {
      sprintf(out_string, "Volunteer cheated!");
    }
    printf("Case #%d: %s\n", t + 1, out_string);

    free (out_string);
  }
}
