// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    long long N, B; scanf("%lld%lld", &B, &N);
    static int M[1000];
    for(int i = 0; i < B; ++i) scanf("%d", &M[i]);
    long long lotime = 0, hitime = N*100001LL;
    while(hitime-lotime>1) {
      long long midtime = (lotime+hitime)/2;
      long long count = 0;
      for(int i = 0; i < B; ++i) {
        count += (midtime-1)/M[i]+1;
      }
      // fprintf(stderr, "midtime=%lld, count=%lld\n", midtime, count);
      if(count<N) lotime = midtime;
      else hitime = midtime;
    }
    // fprintf(stderr, "serve time: %lld\n", lotime);
    long long locount = 0;
    for(int i = 0; i < B; ++i) {
      locount += (lotime-1)/M[i]+1;
    }
    long long remain = N-1-locount;
    int ans = -1;
    for(int i = 0; i < B; ++i) {
      if(lotime%M[i]==0) --remain;
      if(remain<0) {
        ans = i;
        break;
      }
    }
    printf("Case #%d: %d\n", tci+1, ans+1);
  }
  return 0;
}
