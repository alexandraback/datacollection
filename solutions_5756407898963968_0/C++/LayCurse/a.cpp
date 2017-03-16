#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<iostream>
#include<cmath>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int T, cnt=0, in[17], r;

  int i, j, k, loop;
  int ok[17];

  scanf("%d",&T);
  while(T--){
    printf("Case #%d: ", ++cnt);
    rep(i,17) ok[i] = 0;

    rep(loop,2){
      scanf("%d",&r);
      rep(i,16) scanf("%d",in+i);
      rep(i,4) ok[in[(r-1)*4+i]]++;
    }

    k = 0;
    rep(i,17) if(ok[i]==2) k++, j=i;

    if(k==0) puts("Volunteer cheated!");
    if(k==1) printf("%d\n", j);
    if(k>=2) puts("Bad magician!");
  }

  return 0;
}
