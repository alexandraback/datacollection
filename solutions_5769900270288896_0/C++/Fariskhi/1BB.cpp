#include <bits/stdc++.h>
using namespace std;

#define INF 2000000000

// Brute Force Solution

int r, c, n;

int main() {
  int tc;
  scanf("%d", &tc);
  for (int tcNumber = 1; tcNumber <= tc; tcNumber++) {
    scanf("%d %d %d", &r, &c, &n);
    int answer = INF;
    int bound = r*c;
    bool grid[r+5][c+5];
    memset(grid, false, sizeof(grid));
    for (int bit = 0; bit < (1 << bound); bit++) {
      bitset<16> bitSet(bit);
      int now = 0;
      int temp = 0;
      int tenants = 0;
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (bitSet[now++] == 1) {
            grid[i][j] = true;
            tenants++;
          } else {
            grid[i][j] = false;
          }
        }
      }

      if (tenants != n) continue;

      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          if (j + 1 < c && grid[i][j] && grid[i][j+1]) {
            temp++;
          }
          if (i + 1 < r && grid[i][j] && grid[i+1][j]) {
            temp++;
          }
        }
      }
      answer = min(answer, temp);
    }
    printf("Case #%d: %d\n", tcNumber, answer);
  }
}
