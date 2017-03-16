#include <iostream>
#include <vector>

using namespace std;

int solve() {
  int R, C, N;
  cin >> R >> C >> N;

  int ans = 100000;
  vector<vector<bool>> v(R, vector<bool>(C));
  for(int pat = 0; pat < (1<<(R*C)); ++pat) {
    if(__builtin_popcount(pat) != N) continue;
    for(int i = 0; i < R*C; ++i) {
      v[i/C][i%C] = !!(pat & (1<<i));
    }
    int cnt = 0;
    for(int r = 0; r < R; ++r) {
      for(int c = 0; c < C; ++c) {
	if(c+1 < C && v[r][c] && v[r][c+1]) ++cnt;
	if(r+1 < R && v[r][c] && v[r+1][c]) ++cnt;
      }
    }
    if(cnt < ans) ans = cnt;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int T;
  cin >> T;
  for(int C = 1; C <= T; ++C) {
    cout << "Case #" << C << ": " << solve() << endl;
  }
  return 0;
}
