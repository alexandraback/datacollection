#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long Int;

void solve(int idx) {
  int r, c, n;
  cin >> r >> c >> n;

  int best = numeric_limits<int>::max();
  for (int mask = 0; mask < 1<<(r*c); ++mask) {
    vector<vector<int>> b(r, vector<int>(c, 0));
    int count = 0;
    for (int i = 0; i < r*c; ++i) {
      if (mask & (1<<i)) {
	count++;
	b[i/c][i%c] = 1;
      }
    }
    if (count != n) continue;

    int score = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
	if (b[i][j] != 1) continue;
	
	if (i > 0 && b[i][j] == b[i-1][j]) ++score;
	if (i < r-1 && b[i][j] == b[i+1][j]) ++score;
	if (j > 0 && b[i][j] == b[i][j-1]) ++score;
	if (j < c-1 && b[i][j] == b[i][j+1]) ++score;
      }

    best = min(score, best);
  }

  cout << "Case #" << idx << ": " << best/2 << endl;
}

int main() {
  int t; cin >> t;
  for (int idx = 1; idx <= t; ++idx) {
    solve(idx);
  }
}
