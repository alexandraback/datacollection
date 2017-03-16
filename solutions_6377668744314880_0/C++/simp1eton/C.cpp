#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 3005
#define EPS 1e-9
using namespace std;

typedef double LF;
typedef long long int LL;

bool eq(LF a,LF b) {return a-b < EPS && b-a < EPS;}

int z, testcase, N, A[MAXN];
LL X[MAXN], Y[MAXN];
LF ang[MAXN];

bool cmp(int a,int b) {
  return ang[a] < ang[b];
}

bool ccw(int a,int b,int c) {
  return X[a] * Y[b] + X[b] * Y[c] + X[c] * Y[a] - Y[a] * X[b] - Y[b] * X[c] - Y[c] * X[a] >= 0;
}

int main () {
  freopen("C-small-attempt0.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d",&N);
    for (int i=0;i<N;++i) cin >> X[i] >> Y[i];
    z = 0;
    printf("Case #%d:\n",TC);
    if (N <= 3) {
      for (int i=0;i<N;++i) printf("0\n");
      continue;
    }
    for (int z=0;z<N;++z) {
      int ans = N;
      for (int i=0;i<N;++i)
        if (i != z) {
          int tmp = 0;
          for (int j=0;j<N;++j) tmp += ccw(z,i,j);
          ans = min(ans, min(tmp,N-tmp));
        }
      printf("%d\n",ans);
    }
  }
}
