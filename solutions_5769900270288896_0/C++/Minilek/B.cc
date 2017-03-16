#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

int pc(int x) { return !x?0:(x&1)+pc(x>>1); }

int grid[20][20];

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int r, c, n;
    cin >> r >> c >> n;
    int ans = 1000000000;
    for (int mask = 0; mask < 1<<(r*c); ++mask) {
      if (pc(mask) != n) continue;
      memset(grid, 0, sizeof(grid));
      for (int i = 0; i < r*c; ++i) {
	if (mask&(1<<i))
	  grid[i/c + 1][i%c + 1] = 1;
	else
	  grid[i/c + 1][i%c + 1] = 0;
      }
      int tot = 0;
      for (int i = 1; i <= r; ++i)
	for (int j = 1; j <= c; ++j) {
	  if (!grid[i][j]) continue;
	  if (grid[i-1][j]) ++tot;
	  if (grid[i+1][j]) ++tot;
	  if (grid[i][j-1]) ++tot;
	  if (grid[i][j+1]) ++tot;
	}
      assert(tot % 2 == 0);
      ans = min(ans, tot/2);
    }
    printf("Case #%d: %d\n", rr, ans);
  }
  return 0;
}
