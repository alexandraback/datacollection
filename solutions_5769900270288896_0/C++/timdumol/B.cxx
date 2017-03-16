#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  int grid[18][18];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int r,c,n;
    scanf("%d%d%d", &r, &c, &n);

    int ans = r*c*r*c;
    for (int mask = 0; mask < (1 << (r*c)); ++mask) {
      memset(grid, 0, sizeof(grid));
      int count = 0;
      for (int i = 0; i < r*c; ++i) {
        if ((mask >> i) & 1) {
          int x = i % c;
          int y = i / c;
          grid[y+1][x+1] = 1;
          count += 1;
        }
      }
      if (count != n) {
        continue;
      }

      int sad = 0;
      for (int y = 1; y <= r; ++y) {
        for (int x = 1; x <= c; ++x) {
          if (grid[y][x]) {
            if (grid[y-1][x]) {
              sad += 1;
            }
            if (grid[y][x-1]) {
              sad += 1;
            }
          }
          if (sad > ans) break;
        }
      }
      ans = min(ans, sad);
    }
    
    printf("Case #%d: %d\n", ctr+1, ans);
  }
  return 0;
}
