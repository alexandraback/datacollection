#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int test_cases, test_case;
  scanf("%d", &test_cases);
  int num_trees;
  int *X, *Y;
  int *min_logged;
  int num_slopes;
  double *slopes;
  int rise, run;
  int vertical_checked;
  double slope;
  double y_coord;
  int on_left, on_right;
  int i, j, k, l;
  for (test_case = 1; test_case <= test_cases; ++test_case) {
    scanf("%d", &num_trees);
    X = (int *)malloc(sizeof(int) * num_trees);
    Y = (int *)malloc(sizeof(int) * num_trees);
    min_logged = (int *)malloc(sizeof(int) * num_trees);
    num_slopes = 0;
    slopes = (double *)malloc(sizeof(double) * num_trees * num_trees);
    vertical_checked = 0;

    for (i = 0; i < num_trees; ++i) {
      scanf("%d %d", X + i, Y + i);
      min_logged[i] = INT_MAX;
    }
    printf("Case #%d:\n", test_case);
    // We determine the minimum number of trees to be removed by counting the
    // number of trees of either side of the a possible boundary at each tree.
    // We must test all possible slopes
    for (i = 0; i < num_trees; ++i) {
      for (j = i + 1; j < num_trees; ++j) {
        // determine the slope
        rise = Y[j] - Y[i];
        run = X[j] - X[i];
        // avoid dividing by 0
        if (run == 0) {
          // check vertical line, if not already checked
          if (vertical_checked == 0) {
            for (k = 0; k < num_trees; ++k) {
              //printf("vertical %d: (%d, %d)\n", k, X[k], Y[k]);
              on_left = 0;
              on_right = 0;
              for (l = 0; l < num_trees; ++l) {
                if (X[l] < X[k]) {
                  //printf("on left %d: (%d, %d)\n", l, X[l], Y[l]);
                  on_left++;
                } else if (X[l] > X[k]) {
                  //printf("on right %d: (%d, %d)\n", l, X[l], Y[l]);
                  on_right++;
                }
              }
              if (on_left < min_logged[k])
                min_logged[k] = on_left;
              if (on_right < min_logged[k])
                min_logged[k] = on_right;
            }
            vertical_checked = 1;
          }
        } else {
          slope = ((double)rise) / run;
          // check if this slope has already been checked
          for (k = 0; k < num_slopes; ++k) {
            if (slope == slopes[k])
              break;
          }
          //if (k == num_slopes) {
            for (k = 0; k < num_trees; ++k) {
              //printf("%f %d: (%d, %d)\n", slope, k, X[k], Y[k]);
              on_left = 0;
              on_right = 0;
              for (l = 0; l < num_trees; ++l) {
                y_coord = slope * (X[l] - X[k]) + Y[k];
                if (Y[l] < y_coord) {
                  //printf("on left %d: (%d, %d)\n", l, X[l], Y[l]);
                  on_left++;
                } else if (Y[l] > y_coord) {
                  //printf("on right %d: (%d, %d)\n", l, X[l], Y[l]);
                  on_right++;
                }
              }
              if (on_left < min_logged[k])
                min_logged[k] = on_left;
              if (on_right < min_logged[k])
                min_logged[k] = on_right;
            }
            slopes[num_slopes++] = slope;
          //}
        }
      }
    }

    for (i = 0; i < num_trees; ++i)
      printf("%d\n", min_logged[i]);

    free(X);
    free(Y);
    free(min_logged);
    free(slopes);
  }
  return EXIT_SUCCESS;
}
