#include <limits.h>
#include <string.h>
#include <stdio.h>

int N;
char s[101][101];
int M;
char c[101];
int n[101][101];
int min[101];
int max[101];
int sum;
int T, t;
int i, j, m;

int absdiff(int x, int y) {
  if (x < y)
    return y - x;
  else
    return x - y;
}

int main(void) {
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    printf("Case #%d: ", t);

    /* read N and s */
    scanf("%d", &N);
    fgets(s[0], 5, stdin);
    for (i = 0; i < N; i++) {
      fgets(s[i], 200, stdin);
      s[i][strlen(s[i]) - 1] = 0;
    }

    /* find M, c, and n */
    m = 0;
    c[m] = s[0][0];
    n[0][m] = 1;
    for (j = 1; s[0][j]; j++) {
      if (s[0][j] == c[m]) {
        n[0][m]++;
      } else {
        min[m] = n[0][m];
        max[m] = n[0][m];
        m++;
        c[m] = s[0][j];
        n[0][m] = 1;
      }
    }
    min[m] = n[0][m];
    max[m] = n[0][m];
    M = m;
    for (i = 1; i < N; i++) {
      m = 0;
      if (s[i][0] != c[m])
        goto felga_won;
      n[i][m] = 0;
      for (j = 0; s[i][j]; j++) {
        if (s[i][j] == c[m]) {
          n[i][m]++;
        } else {
          if (n[i][m] < min[m])
            min[m] = n[i][m];
          if (n[i][m] > max[m])
            max[m] = n[i][m];
          m++;
          if (s[i][j] != c[m])
            goto felga_won;
          n[i][m] = 1;
        }
      }
      if (n[i][m] < min[m])
        min[m] = n[i][m];
      if (n[i][m] > max[m])
        max[m] = n[i][m];
      if (M != m)
        goto felga_won;
    }

    /* find sum */
    sum = 0;
    for (m = 0; m <= M; m++) {
      int best = INT_MAX;
      for (i = min[m]; i <= max[m]; i++) {
        int cur = 0;
        for (j = 0; j < N; j++)
          cur += absdiff(n[j][m], i);
        if (cur < best)
          best = cur;
      }
      sum += best;
    }
    printf("%d\n", sum);
    continue;
  felga_won:
    printf("Fegla Won\n");
  }
  return 0;
}
