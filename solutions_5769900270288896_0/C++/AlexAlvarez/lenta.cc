#include <iostream>
#include <vector>
using namespace std;

int qtt(vector<vector<int> >& M) {
  int res = 0;

  for (int i = 0; i < M.size(); ++i) {
    for (int j = 0; j < M[i].size(); ++j) {
      if (M[i][j] == 0) continue;

      if (i > 0 and M[i - 1][j] == 1) ++res;
      if (j > 0 and M[i][j - 1] == 1) ++res;
    }
  }

  return res;
}

int solve() {
  int r, c, n;
  cin >> r >> c >> n;

  int t = r*c;
  int res = 1e9;
  for (int i = 0; i < (1 << t); ++i) {
    if (__builtin_popcount(i) != n) continue;
    vector<vector<int> > M(r, vector<int>(c, 0));
    for (int j = 0; j < r; ++j) {
      for (int k = 0; k < c; ++k) {
        if ((i >> (j*c + k))&1) M[j][k] = 1;
      }
    }

    res = min(res, qtt(M));
  }

  return res;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
