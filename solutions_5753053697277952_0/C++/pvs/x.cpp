#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int d[26], m, total;

void dec() {
  int top = 0, itop = 0;;
  for (int i=0; i<m; ++i) if (d[i] > top) { top = d[i]; itop = i; }
  d[itop]--; total--;
  putchar('A'+itop);
  putchar(' ');
}

int main() {
  int n;
  scanf("%d\n", &n);
  for (int i=0; i<n; ++i) {
    printf("Case #%d: ", i+1);
    memset(d, 0, sizeof(d));
    scanf("%d", &m);
    total = 0;
    for (int j=0; j<m; ++j) {
      scanf("%d", &d[j]); total += d[j];
    }
    while (total > 2) dec();
    for (int i=0; i<m; ++i) if (d[i]) putchar('A'+i);
    printf("\n");
  }
}
