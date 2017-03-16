#include <stdio.h>
#define FOR(x, n) for(int x=0; x<n; x++)

#define MAXN 15000

int data[MAXN];

void solve(int testcase) {
  int n;
  scanf("%d", &n);
  FOR(q, n) scanf("%d", &data[q]);
  int method1=0;
  int cur = 0;
  data[n] = 0;

  FOR(q, n) {
    if (cur > data[q]) {
      method1 += cur - data[q];
    }
    cur = data[q];
  }
  int m2 = 0;
  FOR(q, n-1) {
    if (m2 < data[q] - data[q+1])
      m2 = data[q] - data[q+1];
  }
  int method2 = 0;
  //printf("m2 %d\n", m2);
  FOR(q, n-1) {
    if (data[q] <= m2) {
      method2 += data[q];
    } else {
      method2 += m2;
    }
  }
  printf("Case #%d: %d %d\n", testcase+1, method1, method2);

}


int main() {
  int T;
  scanf("%d", &T);
  FOR(q, T) solve(q);
  return 0;
}
