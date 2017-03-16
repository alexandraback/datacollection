#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 1100

int n, m[MAXN];

int main () {
  int teste;
  scanf ("%d", &teste);
  for (int t = 1; t <= teste; t++) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) 
      scanf ("%d", &m[i]);
    int ret1 = 0;
    for (int i = 1; i < n; i++) {
      if (m[i] < m[i - 1])
	ret1 += m[i - 1] - m[i];
    }
    int rate = 0;
    for (int i = 1; i < n; i++) 
      rate = max (rate, m[i - 1] - m[i]);
    int ret2 = 0;
    for (int i = 0; i < n - 1; i++) {
      ret2 += min (m[i], rate);
    }
    printf ("Case #%d: %d %d\n", t, ret1, ret2);
  }
  return 0;
}
