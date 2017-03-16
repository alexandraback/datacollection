#include <stdio.h>
#define FOR(q, n) for(int q=0; q<n; q++)

#define MAX 5000
int x[MAX];
int y[MAX];

void solve(int testcase) {
  int n;
  
  scanf("%d", &n);
  FOR(q, n) scanf("%d %d", &x[q], &y[q]);
  printf("Case #%d:\n", testcase+1);

  FOR(q, n) {
    int best = n-1;

    FOR (direction, n) {
      if (direction == q) continue;
      int left = 0;
      int right = 0;
      FOR(w, n) {
        long long x1, x2, y1, y2;
        x1 = x[direction] - x[q];
        x2 = x[w] - x[q];
        y1 = y[direction] - y[q];
        y2 = y[w] - y[q];
        long long tmp = x1 * y2 - y1 * x2;
        if (tmp > 0) left++;
        if (tmp < 0) right++;
      }
      if (left < best) best = left;
      if (right < best) best = right;
    }

    printf("%d\n", best);
  }
}


int main() {
  int T;
  scanf("%d", &T);
  FOR(q, T) solve(q);
}
