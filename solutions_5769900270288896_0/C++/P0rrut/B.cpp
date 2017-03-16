#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

int R,C,N;
int pl[20][20];
int main(){
  int T;
  cin >> T;
  FOR(t,T){
    printf("Case #%d: ",t+1);
    cin >> R >> C>> N;
    int maxi = 100000000;
    FOR(i,1<<(R*C)){
      if(__builtin_popcount(i)!=N) continue;
      memset(pl,0,sizeof pl);
     // cout << i << endl;
      FOR(j,R*C){
        int x = j/C;
        int y = j%C;
        if(i & (1<<j)){
          pl[x][y]=1;
        }  
      }
      int tot = 0;
      FOR(j,R){
        FOR(k,C){
          if(k<C-1 && pl[j][k] && pl[j][k+1]){
            tot++;
          }
          if(j<R-1 && pl[j][k] && pl[j+1][k])
            tot++;
        }
      }
      maxi = min(maxi,tot);
    }
    cout << maxi << endl;
  }

	return 0;
}
