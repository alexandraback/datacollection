#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define rab(i,a,b) for((i)=(a);(i)<=(b);(i)++)
#define Fi(n) rep(i,n)
#define Fj(n) rep(j,n)
#define Fk(n) rep(k,n)
#define all(v) (v).begin(),(v).end()

int M[10000];
int B;

long long count(long N) {
  long long r = 0;
  int i;

  Fi(B) {
    r += (N/M[i]) + 1;
  }
  return r;
}

long search(int N) {
  long lo,up,mid;

  lo = 0;
  up = 1L<<50;

  while(lo <= up) {
    mid = (lo + up) / 2;

    long r = count(mid);

    if(r == N) break;
    else if(r < N) {
      lo = mid + 1;
    } else {
      up = mid - 1;
    }
  }

  while(true) {
    if(count(mid) >= N) break;
    mid++;
  }

  while(mid >= 0) {
    if(count(mid) < N) break;
    mid--;
  }
  return mid+1;
}

int main() {
  int T, cs;
  int N;
  int i;

  scanf("%d", &T);

  rab(cs,1,T) {
    scanf("%d %d",&B, &N);
    Fi(B) scanf("%d",&M[i]);

    long m = search(N);
    long x = count(m-1);

    vector <int> v;

    Fi(B) {
      if(m % M[i] == 0) v.push_back(i+1);
    }
    int id = (int)(N - x) - 1;

    //printf("%ld %ld\n",m,x);

    printf("Case #%d: %d\n", cs, v[id]);
  }

  return 0;
}
