#include <iostream>
#include <vector>
using namespace std;


int solve(int r, int c, int n) {
  int b = 1e9;
  const int dx[] = {-1,0,1,0};
  const int dy[] = {0,-1,0,1};
  vector<vector<char>> m(r, vector<char>(c, 0));
  for (int i = 0; i < (1 << (r*c)); ++i) {
    int s = 0;
    for (int a = 0; a < r; ++a)
      for (int b= 0; b < c; ++b) {
        if ((i & (1 << (a * c + b)))) {
          m[a][b] = 1;
          s++;
        } else {
          m[a][b] = 0;
        }
      }

    //cerr << i << " " << s << endl;
    if (s == n) {
      int bb = 0;
      for (int a = 0; a < r; ++a)
        for (int b= 0; b < c; ++b)
          for (int k = 0; k < 4; ++k) {
            int x = dx[k]+a;
            int y = dy[k]+b;
            if (x < 0 || y < 0 || x >= r || y >= c) continue;
            if (m[a][b] && m[x][y]) bb++;
        }
      b = min(b,bb);
    }
  }
  return b/2;
}

int main() {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    int r,c,n;
    cin >> r >> c >> n;
    cout << "Case #" << t << ": " <<  solve(r,c,n) << endl;
    cerr << "Case #" << t << ": " <<  solve(r,c,n) << endl;
  }
}
