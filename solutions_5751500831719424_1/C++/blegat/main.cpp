#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100][100];
int  ns[100];
int  cs[100];
char cur[100];
int  num[100];
int n;

#define ABS(x) (((x) < 0) ? -(x) : (x))

int main (void) {
  int T;
  int scanned = scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%d", &n);
    long sum = 0;
    for (int i = 0; i < n; i++) {
      ns[i] = 0;
      char c;
      while ((c = getchar()) == '\n');
      s[i][0] = c;
      for (ns[i] = 1; (c = getchar()) != '\n'; ns[i]++) {
        s[i][ns[i]] = c;
      }
      cs[i] = 0;
    }
    int left = n;
    while (left == n) {
      for (int i = 0; i < n; i++) {
        cur[i] = s[i][cs[i]];
        cs[i]++;
        num[i] = 1;
        for (; cs[i] < ns[i] && s[i][cs[i]] == cur[i]; cs[i]++, num[i]++);
        if (cs[i] == ns[i]) {
          left--;
        }
        if (i > 0 && cur[i] != cur[i-1]) {
          left = -1; // hack
        }
      }
      sort(num, num+n);
      int med = num[n/2];
      for (int i = 0; i < n; i++) {
        sum += ABS(num[i] - med);
      }
    }
    printf("Case #%d: ", currentcase);
    if (left == 0) {
      printf("%ld\n", sum);
    } else {
      printf("Fegla Won\n");
    }
  }
  return 0;
}
