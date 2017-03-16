#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;

int testcase, N, A[MAXN];

bool can(int x) {
  for (int i=1;i<N;++i)
    if (A[i-1] - A[i] > x) return false;
  return true;
}

int get(int x) {
  int ret = 0;
  for (int i=1;i<N;++i) ret += min(A[i-1], x);
  return ret;
}

int main () {
  freopen("A-large.in","r",stdin);
  freopen("A.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d",&N);
    for (int i=0;i<N;++i) scanf("%d",&A[i]);
    int t1 = 0, t2 = 0;
    for (int i=1;i<N;++i)
      if (A[i-1] - A[i] > 0) t1 += A[i-1] - A[i];
    int lo = 0, hi = 10000, mid;
    while (hi > lo) {
      mid = (hi + lo) / 2;
      if (can(mid)) hi = mid;
      else lo = mid+1;
    }
    t2 = get(hi);
    printf("Case #%d: %d %d\n",TC,t1,t2);
  }
}
