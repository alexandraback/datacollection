#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>

using namespace std;

//#define NAME "my"
#define NAME "B-small-attempt0"
//#define NAME "A-large"

int r, c, n;
int g[16][16];

int check() {
  int ret = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) if (g[i][j]) {
      if (j + 1 < c && g[i][j+1]) ret++;
      if (i + 1 < r && g[i+1][j]) ret++;
    }
  return ret;
}

void solveCase(int tc) {
  cin >> r >> c >> n;
  int answer = 1000000000;
  int SZ = 1 << (r*c);
  for (int mask = 0; mask < SZ; mask++) {
    int bits = 0;
    for (int i = 0; i < 16; i++) if ((mask>>i)&1) bits++;
    if (bits != n) continue;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < 16; i++) if ((mask>>i)&1) {
      g[i / c][i % c] = 1;
    }
    int cur = check();
    answer = min(answer, cur);
  }
  cerr << "Case #" << (tc + 1) << ": " << answer << endl;
  cout << "Case #" << (tc + 1) << ": " << answer << endl;
}

void initialize() {
}

int main() {
  freopen(NAME ".in", "rt", stdin);
  freopen(NAME ".out", "wt", stdout);
  int T;
  cin >> T;
  initialize();
  for (int i = 0; i < T; i++) {
    solveCase(i);
  }
  double totalTime = clock() * 1. / CLOCKS_PER_SEC;
  fprintf(stderr, "Time: %.2lf sec\n", totalTime);
  return 0;
}
