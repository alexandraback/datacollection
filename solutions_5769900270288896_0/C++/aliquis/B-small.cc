#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

int solve(int const R, int const C, int const N)
{
  std::vector<bool> v(R*C, false);
  for (int i=R*C-N; i<R*C; ++i)
    v[i] = true;
  int min = INT_MAX;
  do {
    int unhappiness = 0;
    for (int i=0; i<R*C; i+=C)
      for (int j=0; j<C; ++j) {
        if (!v[i+j])
          continue;
        if (i)
          unhappiness += v[(i-C)+j];
        if (j)
          unhappiness += v[i+(j-1)];
      }
    if (min > unhappiness)
      min = unhappiness;
  } while(std::next_permutation(v.begin(), v.end()));
  return min;
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int cases = 1; cases <= T; ++cases) {
    int R, C, N;
    scanf("%d%d%d", &R, &C, &N);
    printf("Case #%d: %d\n", cases, solve(R, C, N));
  }
  return 0;
}
