#include <iostream>
#include <cstdio>
#define MAXN 1005
using namespace std;

typedef long long int LL;

int N,B,testcase;
LL A[MAXN];

LL get(LL x) {
  LL ret = 0;
  for (int i=1;i<=B;++i) ret += (x + A[i]-1ll) / A[i];
  return ret;
}

int main () {
  freopen("B-small-attempt0.in","r",stdin);
  freopen("B.out","w",stdout);
  scanf("%d",&testcase);
  for (int TC=1;TC<=testcase;++TC) {
    scanf("%d%d",&B,&N);
    for (int i=1;i<=B;++i) scanf("%lld",&A[i]);
    LL lo = 0, hi = (1ll<<61), mid;
    while (hi > lo) {
      mid = (hi + lo + 1ll) / 2ll;
      if (get(mid) < N) lo = mid;
      else hi = mid-1ll;
    }
    LL tmp = get(hi);
    for (int i=1;i<=B;++i)
      if (hi % A[i] == 0) {
        ++tmp;
        if (tmp == N) {
          printf("Case #%d: %d\n",TC, i);
          break;
        }
      }
  }
}
