#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  for (int N = 0; N < T; ++N) {
    int input[2][4];
    int r;
    for (int k = 0; k < 2; ++k) {
      scanf("%d", &r);
      for (int i = 0; i < 4; ++i) {
        if (i + 1 == r) {
          for (int j = 0; j < 4; ++j) {
            scanf("%d", &input[k][j]);
          }
        } else {
          for (int j = 0; j < 4; ++j) {
            scanf("%*d");
          }
        }
      }
    }
    int common = 0;
    int result;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (input[0][i] == input[1][j]) {
          result = input[0][i];
          ++common;
        }
      }
    }
    printf("Case #%d: ", N+1);
    if (common == 0) {
      printf("Volunteer cheated!\n");
    } else if (common == 1) {
      printf("%d\n", result);
    } else {
      printf("Bad magician!\n");
    }
  }
  return 0;
}
