#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N = 16;

int T;
int R, C, N;
int dx[] = {0, -1, 0, +1};
int dy[] = {1, 0, -1, 0};
int G[MAX_N][MAX_N];
int outside(int x, int y){
  return x < 0 || x >= R || y < 0 || y >= C;
}

int solve(){
  scanf("%d%d%d", &R, &C, &N);
  int res = 1000000;
  int n = R * C;
  for(int i = 0; i < (1 << n); i++){
    memset(G, 0, sizeof G);
    int need = N;
    for(int j = 0; j < n; j++){
      if(!((i >> j) & 1)) continue;
      int x = j / C;
      int y = j % C;
      G[x][y] = 1;
      need --;
    }
    if(need != 0) continue;
    int r = 0;
    for(int x = 0; x < R; x++){
      for(int y = 0; y < C; y++){
        if(!G[x][y]) continue;
        for(int d = 0; d < 4; d++){
          int nx = x + dx[d];
          int ny = y + dy[d];
          if(!outside(nx, ny) && G[nx][ny]){
            r ++;
          }
        }
      }
    }
    if(res > r / 2){
      res = r / 2;
    }
  }
  return res; 
}

int main(){
  scanf("%d", &T);
  for(int cn = 1; cn <= T; cn++){
    printf("Case #%d: %d\n", cn, solve());
  }
  return 0;
}
