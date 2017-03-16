#include <iostream>
#include <map>
#include <fstream>

using namespace std;

const int INF = 1e+9;
const int LIM = 17;

int mp[LIM][LIM][LIM];

int get_cnt_bits(int mask) {
  int res = 0;
  while (mask > 0) {
    res += (mask & 1);
    mask = mask >> 1;
  }
  return res;
}

bool bit(int mask, int bit) {
  return ((mask >> bit) & 1);
}

int check(int r, int c, int mask) {
  int res = 0;
  int cb = 0;
  int lim = r * c;
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j) {
      if (bit(mask, cb) && cb + c < lim && bit(mask, cb + c))
        ++res;
      if (bit(mask, cb) && j + 1 < c && bit(mask, cb + 1))
        ++res;
      ++cb;
    }
  return res;
}

int get_ans(int r, int c, int n) {
  if (mp[r][c][n] != INF)
    return mp[r][c][n];
  for (int mask = 0; mask < (1 << r * c); ++mask) {
    int cnt_b = get_cnt_bits(mask);
    int unhap = check(r, c, mask);
    mp[r][c][cnt_b] = min(mp[r][c][cnt_b], unhap);
  }
  return mp[r][c][n];
}

void init() {
  for (int i = 0; i < LIM; ++i)
    for (int j = 0; j < LIM; ++j)
      for (int k = 0; k < LIM; ++k)
        mp[i][j][k] = INF;
}

int main() {
  ifstream cin("B-small-attempt2.in");
  ofstream cout("B_small_out");
  init();
  int tests;
  cin >> tests;
  for (int test = 0; test < tests; ++test) {
    int r, c, n;
    cin >> r >> c >> n;
    cout << "Case #" << test + 1 << ": " << get_ans(r, c, n) << "\n";
  }
  return 0;
}
