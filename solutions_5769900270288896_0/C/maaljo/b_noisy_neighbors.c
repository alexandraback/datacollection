#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int T, N, R, C;
  scanf("%d", &T);
  int *apartments;
  int current_case = 1;
  int row, col, i;
  int unhappiness;
  int max, max_index, residents;
  while (current_case <= T) {
    scanf("%d %d %d", &R, &C, &N);
    //printf("allocating appartments\n");
    apartments = (int *)malloc(sizeof(int) * R * C);
    for (row = 0; row < R; ++row)
      for (col = 0; col < C; ++col) {
        apartments[row * C + col] = 4;
        if (row == 0) 
          apartments[row * C + col] -= 1;
        if (row == R - 1)
          apartments[row * C + col] -= 1;
        if (col == 0)
          apartments[row * C + col] -= 1;
        if (col == C - 1)
          apartments[row * C + col] -= 1;
      }
    residents = R * C;
    max = -1;
    while (residents > N) {
      //printf("%d residents remain\n", residents);
      max_index = 0;
      for (i = 0; i < R * C; ++i) {
        if (apartments[i] > apartments[max_index]) {
          max_index = i;
          if (apartments[max_index] == max)
            break;
        }
      }
      //printf("removing %d\n", max_index);
      max = apartments[max_index];
      apartments[max_index] = 0;
      if (max_index >= C)
        apartments[max_index - C] -= 1;
      if (max_index < (R - 1) * C)
        apartments[max_index + C] -= 1;
      if (max_index % C != 0)
        apartments[max_index - 1] -= 1;
      if (max_index % C != C - 1)
        apartments[max_index + 1] -= 1;
      residents -= 1;
    }

    unhappiness = 0;
    for (i = 0; i < R * C; ++i)
      if (apartments[i] > 0)
        unhappiness += apartments[i];
    // double counted
    unhappiness /= 2;

    printf("Case #%d: %d\n", current_case, unhappiness);
    ++current_case;
    free(apartments);
  }

  return EXIT_SUCCESS;
}
