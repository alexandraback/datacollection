#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <functional>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

const string PROGRAM_NAME = "google";

int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int main() {
  freopen((PROGRAM_NAME + ".in").c_str(), "r", stdin);
  freopen((PROGRAM_NAME + ".out").c_str(), "w", stdout);
  int nt;
  cin >> nt;
  for (int it = 1; it <= nt; it++) {
    int r, c, n;
    cin >> r >> c >> n;
    int K = r * c;
    vector<vector<char> > t(r, vector<char>(c, '.'));

    int answer = -1;
    for (int mask = 0; mask < (1 << K); ++mask) {
      int cnt = 0;
      for (int j = 0; j < K; ++j) {
        if (mask & (1 << j)) {
          cnt++;
        }
      }
      if (cnt != n) {
        continue;
      }

      for (int j = 0; j < K; ++j) {
        if (mask & (1 << j)) {
          t[j / c][j % c] = 'X';
        }
      }

      int broi = 0;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          if (t[i][j] == 'X') {
            for (int l = 1; l < 3; ++l) {
              int tx = i + moves[l][0];
              int ty = j + moves[l][1];
              if (tx < 0 || tx >= r || ty < 0 || ty >= c) {
                continue;
              }
              if (t[tx][ty] == 'X') {
                broi++;
              }
            }
          }
        }
      }
      if (answer == -1 || answer > broi) {
        answer = broi;
      }
      for (int j = 0; j < K; ++j) {
        if (mask & (1 << j)) {
          t[j / c][j % c] = '.';
        }
      }

    }
    cout << "Case #" << it << ": " << answer << endl;
  }
  return 0;
}
