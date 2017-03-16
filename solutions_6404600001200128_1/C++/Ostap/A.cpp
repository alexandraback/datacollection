#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
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

int A[1010];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    int y, z;
    y = z = 0;
    int md = 0;
    for (int i = 0; i+1 < N; ++i)
      if (A[i] > A[i+1]) {
	y += A[i] - A[i+1];
	md = max(md, A[i] - A[i+1]);
      }

    for (int i = 0; i+1 < N; ++i) {
      z += min(A[i], md);
    }

    printf("Case #%d: %d %d\n", t+1, y, z);

    //    fprintf(stderr, "Done %d/$d\n", t+1, T);
  }

  return 0;
};
