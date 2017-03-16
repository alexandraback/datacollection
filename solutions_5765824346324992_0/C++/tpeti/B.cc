#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
  int T;
  scanf("%d",&T);
  for (int n=1;n<=T;++n) {
    printf("Case #%d: ",n);
    int B,N;
    scanf("%d%d",&B,&N);
    vector<int> v(B,0);
    for (int i=0;i<B;++i) scanf("%d",&v[i]);
    if (N<=B) {
      printf("%d\n",N);
      continue;
    }
    ll a=0,b=100000000000000ll;
    ll x;
    while (b-a>1ll) {
      ll c=(a+b)/2ll;
      x=B;
      for (int i=0;i<B;++i) x+=c/ll(v[i]);
      if (x<N) a=c; else b=c;
    }
    x=B;
    for (int i=0;i<B;++i) x+=b/ll(v[i]);
    //    fprintf(stderr,"%lld %lld\n",b,x);
    int i=B-1;
    while (i>=0) {
      if (b%ll(v[i])==0ll) {
	if (x==N) break;
	--x;
      }
      --i;
    }
    assert(i>=0);
    printf("%d\n",i+1);
  }
  return 0;
}

