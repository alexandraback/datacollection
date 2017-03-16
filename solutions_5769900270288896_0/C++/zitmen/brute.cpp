#include <iostream>
using namespace std;

int R, C, N;
bool building[16][16];
const int MAXVAL = 100000;

int count(int r, int c) {
  int cnt = 0;
  if (r > 0 && building[r-1][c]) cnt++;
  if (c > 0 && building[r][c-1]) cnt++;
  if (r+1 < R && building[r+1][c]) cnt++;
  if (c+1 < C && building[r][c+1]) cnt++;
  return cnt;
}

int solve(int pos, int n) {
  if (pos == R*C && n > 0) return MAXVAL;
  if (n <= 0) return 0;
  int r = pos / C;
  int c = pos % C;
  int a = solve(pos+1, n);
  building[r][c] = true;
  int b = count(r, c) + solve(pos+1, n-1);
  building[r][c] = false;
  return min(a, b);
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> R >> C >> N;
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        building[r][c] = false;
      }
    }
    cout << "Case #" << t << ": " << solve(0, N) << endl;
  }
  return 0;
}