#include <stdio.h>

int R, C, N;

bool check(int bit, int r, int c) {
  if(r < 0 || c < 0 || r >= R || c >= C) return false;
  int idx = r*C + c;
  if(bit & (1<<idx)) return true;
  return false;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int test;
  scanf("%d", &test);
  for(int t=1; t<=test; ++t) {
    scanf("%d %d %d", &R, &C, &N);
    int cost = 2000000000, upper = 1<<(R*C);
    for(int bit=0; bit<upper; ++bit) {
      if(__builtin_popcount(bit) != N) continue;
      int ccost = 0;
      for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
          if(check(bit, i, j)) {
            if(check(bit, i+1, j)) ccost++;
            if(check(bit, i, j+1)) ccost++;
          }
        }
      }
      if(cost > ccost) cost = ccost;
    }
    printf("Case #%d: %d\n", t, cost);
  }
  return 0;
}