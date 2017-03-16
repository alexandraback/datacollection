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

  int arr[1024];
  int arr2[1024];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
    }
    int a = 0;
    int b = 0;
    int maxim = arr[0];
    int max_delta = 0;
    for (int i = 1; i < n; ++i) {
      if (arr[i] < arr[i-1]) {
        a += arr[i-1] - arr[i];
        max_delta = max(max_delta, arr[i-1] - arr[i]);
      }
      maxim = max(arr[i], maxim);
    }

    if (a == 0) {
      printf("Case #%d: 0 0\n", ctr+1);
      continue;
    }

    
    for (int k = max_delta; k <= maxim; ++k) {
      int cval = arr[0];
      int eaten = 0;
      bool ok = true;
      for (int i = 1; i < n; ++i) {
        eaten += min(cval, k);
        cval = max(cval - k, 0);
        if (cval > arr[i]) {
          ok = false;
          break;
        }
        cval = arr[i];
      }
      if (ok) {
        b = eaten;
        break;
      }
    }
    printf("Case #%d: %d %d\n", ctr+1, a, b);
  }
  return 0;
}
