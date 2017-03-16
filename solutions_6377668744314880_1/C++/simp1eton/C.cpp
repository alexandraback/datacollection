#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 3005
#define EPS 1e-12
using namespace std;

typedef double LF;
typedef long long int LL;

const LF PI = 2.0 * acos(0);
bool eq(LF a,LF b) {return a-b < EPS && b-a < EPS;}

int testcase, N;
LL X[MAXN], Y[MAXN];
LF A[3*MAXN];


bool ccw(int a,int b,int c) {
  return X[a] * Y[b] + X[b] * Y[c] + X[c] * Y[a] - Y[a] * X[b] - Y[b] * X[c] - Y[c] * X[a] >= 0;
}

int main () {
  freopen("C-large.in","r",stdin);
  freopen("C.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d",&N);
    for (int i=0;i<N;++i) cin >> X[i] >> Y[i];
    printf("Case #%d:\n",TC);
    if (N <= 3) {
      for (int i=0;i<N;++i) printf("0\n");
      continue;
    }
    for (int z=0;z<N;++z) {
      int L = 0, ans = N;
      for (int i=0;i<N;++i)
        if (i != z) A[L++] = atan2(Y[i]-Y[z],X[i]-X[z]);
      sort(A,A+L);
      for (int i=L;i<2*L;++i) A[i] = A[i-L] + 2.0 * PI;
     // printf("%d: ",z); for (int i=0;i<2*L;++i) printf("%.5lf ",A[i]); printf("\n");
      int t = 0;
      for (int i=0;i<L;++i) {
        while (t < i+L && A[t] - A[i] < PI || eq(A[t]-A[i],PI)) t++;
       // printf("(%d, %d)\n",i,t);
        ans = min(ans, N-t+i-1);
      }
      printf("%d\n",ans);
    }
  }
}
