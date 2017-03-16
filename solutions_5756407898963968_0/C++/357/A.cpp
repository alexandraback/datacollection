#include <stdio.h>
#include <stdlib.h>

int a[5][5], b[5];

int main(int argc, char* argv[]) {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int o = 1; o <= T; ++o) {
    printf("Case #%d: ", o);

    int k;
    scanf("%d", &k); --k;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        scanf("%d", &a[i][j]);
    for (int i = 0; i < 4; ++i)
      b[i] = a[k][i];

    scanf("%d", &k); --k;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        scanf("%d", &a[i][j]);

    int times = 0, ans;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        if (a[k][i] == b[j])
          ++times, ans = b[j];
    if (times == 0)
      printf("Volunteer cheated!\n");
    else if (times > 1)
      printf("Bad magician!\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
