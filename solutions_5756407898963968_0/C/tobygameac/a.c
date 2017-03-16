#include <stdio.h>

int main() {
  int T, C = 1;
  scanf("%d", &T);
  while (T--) {
    printf("Case #%d: ", C++);
    int round, rec[2][4];
    for (round = 0; round < 2; round++) {
      int ans;
      scanf("%d", &ans);
      int r, c, temp;
      for (r = 0; r < 4; r++) {
        for (c = 0; c < 4; c++) {
          if (r == ans - 1) {
            scanf("%d", &rec[round][c]);
          } else {
            scanf("%d", &temp);
          }
        }
      }
    }
    int i, j, target, count = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (rec[0][i] == rec[1][j]) {
          count++;
          target = rec[0][i];
        }
      }
    }
    if (!count) {
      puts("Volunteer cheated!");
    } else if (count == 1) {
      printf("%d\n", target);
    } else {
      puts("Bad magician!");
    }
  }
  return 0;
}
