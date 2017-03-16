#include <iostream>
#define MAX_R 100
#define MAX_C 100

using namespace std;

int FIELD[MAX_R][MAX_C];

int score(int x, int r, int c)
{
  int ret = 0;
  for (int i = 0; i < MAX_R; ++i) {
    for (int j = 0; j < MAX_C; ++j) {
      FIELD[i][j] = 0;
    }
  }
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      FIELD[i][j] = (x & 1);
      x >>= 1;
    }
  }
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      ret += ((FIELD[i][j] && FIELD[i][j+1]) & 1);
      ret += ((FIELD[i][j] && FIELD[i+1][j]) & 1);
    }
  }
  return ret;
}

int bincnt(int x)
{
  int ret = 0;
  while (x > 0) {
    ret += (x & 1);
    x >>= 1;
  }
  return ret;
}

int solve()
{
  int r, c, n;
  cin >> r >> c >> n;
  int ret = 10001;
  for (int i = 0; i < (1 << (r * c)); ++i) {
    if (bincnt(i) == n)
      ret = min(ret, score(i, r, c));
  }
  return ret;
}

int main()
{
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": " << solve() << endl;
  }
  return 0;
}
