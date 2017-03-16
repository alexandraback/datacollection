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

int A[2][4];

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int tmp;
    for (int kk = 0; kk < 2; ++kk) {
      int r;
      scanf("%d", &r);
      --r;
      for (int i = 0; i < 4; ++i) {
	for (int j = 0; j < 4; ++j)
	  if (i == r) {
	    scanf("%d", &A[kk][j]);
	  } else {
	    scanf("%d", &tmp);
	  }
      }
    }
    int k = 0;
    int v = 0;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
	if (A[0][i] == A[1][j]) {
	  ++k;
	  v = A[0][i];
	}

    printf ("Case #%d: ", t+1);
    if (k == 0)
      printf("Volunteer cheated!\n");
    else if (k == 1)
      printf ("%d\n", v);
    else
      printf("Bad magician!\n");
  }

  return 0;
};
