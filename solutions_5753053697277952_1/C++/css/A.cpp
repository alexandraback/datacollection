#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, sum, p[57];

char ch(int x) {
  return (char)((int)'A' + x);
}

int find() {
  int m = -1;
  for (int i = 0; i < n; i++)
    if (p[i] > 0) m = i;
  for (int i = 0; i < n; i++)
    if (p[i] > p[m]) m = i;
  return m;
}

void check(int t) {
  p[t]--;

  int sum = 0;
  for (int i = 0; i < n; i++) sum += p[i];
  for (int i = 0; i < n; i++) 
    if (2 * p[i] > sum) {
      p[i]--;
      printf(" %c%c", ch(t), ch(i));
      return;
    }

  printf(" %c", ch(t));
}

int main()
{
  freopen("A-large.in", "r", stdin);
  freopen("output.out", "w", stdout);

  scanf("%d", &T);
  for (int cou = 1; cou <= T; cou++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    printf("Case #%d:", cou);
    for (int t = find(); t >= 0; t = find()) check(t);
    printf("\n");
  }

  fclose(stdin);
  fclose(stdout);
}
