#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
const int MAXK = 16;
int T, R, C, N;
bool st[MAXK];

bool get(int r, int c){
  return st[C * r + c];
}

void dfs(int d, int n, int &res){
  if(d == R * C){
    if(n == N){
      int r = 0;
      for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
          if(!get(i, j)) continue;
          if(i < R - 1) r += get(i + 1, j);
          if(j < C - 1) r += get(i, j + 1);
        }
      }
      res = min(res, r);
    }
    return;
  }
  dfs(d + 1, n, res);
  st[d] = 1;
  dfs(d + 1, n + 1, res);
  st[d] = 0;
}

int main(){
  cin >> T;
  for(int _t = 1; _t <= T; _t++){
    printf("Case #%d: ", _t);
    cin >> R >> C >> N;
    int res = INF;
    dfs(0, 0, res);
    cout << res << '\n';
  }
}
