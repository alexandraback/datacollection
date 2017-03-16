#include <memory.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;

int R;
int C;
bool map[20][20];
bool answered;
int cur_answer;

int CalcUnhappiness() {
  int result = 0;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (!map[i][j]) {
        continue;
      }
      if (i > 0 && map[i - 1][j]) {
        ++result;
      }
      if (j > 0 && map[i][j - 1]) {
        ++result;
      }
    }
  }
  return result;
}

void Rec(int r, int c, int remaining) {
  if (remaining == 0) {
    if (!answered) {
      cur_answer = CalcUnhappiness();
    } else {
      cur_answer = min(cur_answer, CalcUnhappiness());
    }
    answered = true;
    return;
  }
  int nextr = r;
  int nextc = c + 1;
  if (nextc >= C) {
    nextc = 0;
    ++nextr;
  }
  if (C - c + (R - r - 1) * C > remaining) {
    Rec(nextr, nextc, remaining);
  }
  map[r][c] = true;
  Rec(nextr, nextc, remaining - 1);
  map[r][c] = false;
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int N = 0;
    cin >> R >> C >> N;

    memset(map, 0, sizeof(map));
    answered = false;

    Rec(0, 0, N);

    cout << "Case #" << tt << ": " << cur_answer << "\n";
  }
  
  return 0;
}
