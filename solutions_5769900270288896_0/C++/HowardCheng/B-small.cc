#include <iostream>
#include <algorithm>

using namespace std;

void solve()
{
  const int dr[] = {-1, 1, 0, 0};
  const int dc[] = {0,0,-1,1};
  int R, C, N;
  cin >> R >> C >> N;

  int best = 2*N;
  for (int bm = 0; bm < (1UL << (R*C)); bm++) {
    if (__builtin_popcount(bm) != N) continue;
    bool grid[16][16];
    int k = 0;
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
	grid[r][c] = (bm & (1UL << k));
	k++;
      }
    }
    int count = 0;
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
	if (!grid[r][c]) continue;
	for (int d = 0; d < 4; d++) {
	  int r2 = r + dr[d], c2 = c + dc[d];
	  if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C &&
	      grid[r2][c2]) {
	    count++;
	  }
	}
      }
    }
    best = min(best, count/2);
  }
  cout << best << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
