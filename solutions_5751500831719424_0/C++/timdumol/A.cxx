#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <complex>
#include <numeric>
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
  int mat[128][128];
  char arr[128];
  char str[128];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(mat, 0, sizeof(mat));
    memset(arr, 0, sizeof(arr));

    int m = 0;
    bool ok = true;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", str);
      int len = strlen(str);
      int cnt = 0;
      if (ok) {
        if (i == 0) {
          arr[0] = str[0];
          mat[0][i] = 1;
          for (int j = 1; j < len; ++j) {
            if (str[j] != arr[m]) {
              ++m;
              arr[m] = str[j];
            }
            ++mat[m][i];
          }
          ++m;
        } else {
          for (int j = 0; j < len; ++j) {
            if (str[j] != arr[cnt]) {
              if (mat[cnt][i] == 0) {
                ok = false;
                break;
              } else {
                ++cnt;
                if (str[j] != arr[cnt]) {
                  ok = false;
                  break;
                }
              }
            }
            ++mat[cnt][i];
          }
          ++cnt;
          if (cnt != m) {
            ok = false;
          }
        }
      }
    }

    if (!ok) {
      printf("Case #%d: Fegla Won\n", ctr+1);
    } else {
      int sum = 0;
      for (int i = 0; i < m; ++i) {
        int best = 1 << 29;
        for (int j = 0; j < n; ++j) {
          int curr = 0;
          for (int k = 0; k < n; ++k) {
            curr += abs(mat[i][j] - mat[i][k]);
          }
          best = min(curr, best);
        }
        sum += best;
      }
      printf("Case #%d: %d\n", ctr+1, sum);
    }
    
  }
  return 0;
}
