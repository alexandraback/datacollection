#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

const int maxn = 20 + 10;
char st[maxn];
int s, b[maxn][maxn];

int count_one(int x) {
  int num = 0;
  while (x > 0) {
    num += 1;
    x -= x & (-x);
  }
  return num;
}

int bf(int r, int c, int n) {
  memset(b, 0, sizeof(b));
  if (n <= 1) return 0;
  int num = r * c;
  int ans = n * 4;
  for (int st = 1; st <= (1 << num) - 1; st++) {
    if (count_one(st) != n) continue;
    int tmp = 0;
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        int t = (i-1) * c + j - 1;
        b[i][j] = (st >> t) & 1;
        if (b[i][j] == 1) {
          tmp += (b[i-1][j] == 1);
          tmp += (b[i][j-1] == 1);
        }
      }
    }
    if (tmp < ans) ans = tmp;
  }
  return ans;
}

int main()
{
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B_small.out", "w", stdout);
  int TextN;
  cin >> TextN;
  int R, C, N;
  for (int TT = 1; TT <= TextN; TT++) {
    cin >> R >> C >> N;
    cout << "Case " << "#" << TT << ": " << bf(R, C, N) << endl;
  }
  return 0;
}