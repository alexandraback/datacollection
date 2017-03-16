#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

int vx[4] = {0,0,1,-1};
int vy[4] = {1,-1,0,0};

int solve(int R, int C, int N){
  if(N<=1) return 0;
  int ret = 10000000;

  for(int S=0; S<(1<<(R*C)); S++){
    int num = 0;
    vector<vector<int> > G(R, vector<int>(C, 0));
    int idx = 0;
    rep(i,R){
      rep(j,C){
        if((S>>idx)&1){
          num++;
          G[i][j] = 1;
        }
        idx++;
      }
    }
    
    if(num == N){
      int cnt = 0;
      rep(i,R){
        rep(j,C){
          if(G[i][j] == 1){
            rep(k,4){
              int ny = i+vy[k], nx = j+vx[k];
              if(0<=ny&&ny<R && 0<=nx&&nx<C){
                if(G[ny][nx] == 1) cnt++;
              }
            }
          }
          //cout << G[i][j];
        }
        //cout << endl;
      }
      //cout << endl;
      ret = min(ret, cnt/2);
    }
  }
  return ret;
}


int main(){
  int T;

  cin >> T;
  rep(t,T){
    int R, C, N;
    cin >> R >> C >> N;
    
    cout << "Case #" << t+1 << ": " << solve(R, C, N) << endl;
  }
  
  return 0;
}
