#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<numeric>
#include<deque>
using namespace std;
#define LL long long

int K;
int N;
int M[2000];

LL calc(LL T) {
  LL tot=0;
  for(int i=1;i<=N;++i) {
    tot += 1 + T / M[i];
  }
  return tot;
}

int run(){
  scanf("%d %d", &N, &K);
  for(int i=1;i<=N;++i)scanf("%d", M+i);
  if(K <= N) return K;
  
  LL lo = 0, hi = *min_element(M+1,M+N+1) * (LL)K, mid;
  while(lo + 1 < hi) {
    mid = lo + hi >> 1;
    if(calc(mid) >= K) hi= mid;
    else lo= mid;
  }
  
  //cerr << "final time = "<<hi<<endl;
  
  int prev = calc(lo);
  K-= prev;
  for(int i=1;i<=N;++i)
    if(hi % M[i] == 0) {
      if(!--K) return i;
    }
  return -1;
}

int main() {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);
  int test;
  scanf("%d", &test);
  for(int no=1;no<=test;++no)
    printf("Case #%d: %d\n", no, run());
}
