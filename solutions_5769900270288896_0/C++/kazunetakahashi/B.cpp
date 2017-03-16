#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void init() {
}

// 変数を書く

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int N, R, C;

void input() {
  cin >> R >> C >> N;
}

void output() {
  bool room[16][16];
  int ans = 1000000;
  int c = R*C;
  for (int i=0; i<(1 << c); i++) {
    int cnt = 0;
    for (int j=0; j<c; j++) {
      if (((i >> j) & 1) == 1) {
        cnt++;
      }
    }
    if (cnt != N) continue;
    fill(&room[0][0], &room[0][0]+16*16, false);
    for (int j=0; j<c; j++) {
      if (((i >> j) & 1) == 1) {
        int col = j%R;
        int row = j/R;
        room[col][row] = true;
      }
    }
    int tans = 0;
    for (auto j=0; j<R; j++) {
      for (auto k=0; k<C; k++) {
        if (room[j][k]) {
          for (auto l=0; l<4; l++) {
            int nx = j+dx[l];
            int ny = k+dy[l];
            if (0 <= nx && nx < R && 0 <= ny && ny < C && room[nx][ny]) {
              tans++;
            }
          }
        }
      }
    }
    ans = min(ans, tans);
  }
  assert(ans < 100000);
  assert(ans%2 == 0);
  cout << ans/2 << endl;
}

int main() {
  init();
  int T;
  cin >> T;
  for (auto t=1; t<=T; t++) {
    cout << "Case #" << t << ": "; 
    input();
    output();
  }
}
