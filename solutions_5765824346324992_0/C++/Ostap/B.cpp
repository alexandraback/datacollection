#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

int M[1010];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int B, N;
    scanf("%d%d", &B, &N);
    for (int i = 0; i < B; ++i)
      scanf("%d", &M[i]);

    if (N <= B) {
      printf("Case #%d: %d\n", t+1, N);
      continue;
    }

    Int lb, ub, cb;
    lb = 0;
    ub = M[0] * (Int)(N+10);
    while (ub - lb > 1) {
      cb = (ub + lb) >> 1;
      Int cnt = 0;
      for (int i = 0; i < B; ++i) {
	cnt += cb / M[i] + 1;
      }
      if (cnt >= N)
	ub = cb;
      else
	lb = cb;
    }

    Int time = ub;
    Int sit = 0;
    for (int i = 0; i < B; ++i) {
      sit += (time + M[i] - 1) / M[i];
    }
    int stand = N - sit;
    int pos = 0;
    for (int i = 0; i < B; ++i) {
      if (time % M[i] == 0)
	--stand;
      if (stand == 0) {
	pos = i;
	break;
      }
    }

    printf("Case #%d: %d\n", t+1, pos+1);

    fprintf(stderr, "Done %d/%d\n", t+1, T);
  }

  return 0;
};
