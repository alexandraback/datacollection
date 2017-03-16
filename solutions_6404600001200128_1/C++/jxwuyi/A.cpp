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

int A[2000];
int N;
int tot=0;
int solve1() {
  int ret=0;
  for(int i=2;i<=N;++i) {
    if(A[i]<A[i-1])ret+=A[i-1]-A[i];
  }
  return ret;
}

int solve2() {
  int ret=tot;
  int up = *max_element(A+1,A+N+1);
  for(int rat=0;rat<=up;++rat) {
    bool ok=true;
    int cur=0;
    for(int i=2;i<=N && ok;++i) {
      if(rat == 0) {
        if(A[i] < A[i-1]) {
          ok=false;
          break;
        }
        continue;
      }
      //int k = min(10, A[i-1] / rat);
      int end = max(A[i-1] - rat, 0);
      if(end > A[i]) {
        ok=false;
        break;
      }
      //end = A[i-1] - k * rat;
      //end = max(0, A[i-1] - 10 * rat);
      //cur += A[i-1] - end;
      //cur += k * rat;
      cur += A[i-1] - end;
    }
    if(ok)ret=min(ret,cur);
  }
  return ret;
}

int run() {
  scanf("%d", &N);
  tot=0;
  for(int i=1;i<=N;++i) {
    scanf("%d", A+i);
    tot+=A[i];
  }
  printf("%d", solve1());
  printf(" %d\n", solve2());
}

int main() {
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  int test;
  scanf("%d", &test);
  for(int no=1;no<=test;++no)
    {
      printf("Case #%d: ", no);
      run();
    }
}

