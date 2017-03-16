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

Int X[5000];
Int Y[5000];
int R[5000];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%lld%lld", &X[i], &Y[i]);
      R[i] = N+1;
    }
    if (N == 1) R[0] = 0;
  
    for (int a = 0; a < N; ++a)
      for (int b = a+1; b < N; ++b) {
	int left = 0;
	int right = 0;
	Int x1 = X[b] - X[a];
	Int y1 = Y[b] - Y[a];
	for (int i = 0; i < N; ++i) {
	  Int x2 = X[i] - X[a];
	  Int y2 = Y[i] - Y[a];
	  Int prod = x1 * y2 - y1 * x2;
	  if (prod < 0) left++;
	  if (prod > 0) right++;
	}
	int r = min(left, right);
	R[a] = min(R[a], r);
	R[b] = min(R[b], r);
      }

    printf("Case #%d:\n", t+1);
    for (int i = 0; i < N; ++i)
      printf("%d\n", R[i]);

    fprintf(stderr, "Done %d/%d\n", t+1, T);
  }

  return 0;
};
