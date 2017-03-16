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

  llong barbers[100001];
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    int b, n;
    scanf("%d %d", &b, &n);
    multiset<pair<ullong, int> > pq;
    for (int i = 0; i < b; ++i) {
      scanf("%lld", &barbers[i]);
    }

    llong maxim = *max_element(barbers, barbers + b);
    llong lo = 0;
    llong hi = maxim * n;

    int ans = 0;
    while (lo < hi) {
      llong mid = lo + (hi-lo)/2;
      llong t = mid;
      bool p = true;
      int cnt = 0;
      llong n_processed = 0;
      for (int i = 0; i < b; ++i) {
        if (t % barbers[i] == 0) ++cnt;

        n_processed += t/barbers[i];
      }
      #ifdef DEBUG
      printf("(%lld - %lld - %lld) %d %lld\n", lo, mid, hi, cnt, n_processed);
      #endif
      if (cnt == 0) p = false;
      if (p) {
        if (n - cnt <= n_processed && n_processed <= n - 1) {
          // done
          int d = 0;
          int target = n - n_processed;
          #ifdef DEBUG
          printf("Target is %d\n", target);
          #endif
          for (int i = 0; i < b; ++i) {
            if (t % barbers[i] == 0) {
              ++d;
              if (target == d) {
                ans = i+1;
                #ifdef DEBUG
                printf("Found target to be %d\n", ans);
                #endif
                break;
              }
            }
          }
          
        } else {
          p = false;
        }
      }

      if (p) {
        #ifdef DEBUG
        printf("got the answer\n");
        #endif
        break;
      }

      if (n_processed + b > n) {
        #ifdef DEBUG
        printf("too high\n");
        #endif
        hi = mid;
      } else {
        #ifdef DEBUG
        printf("too low\n");
        #endif
        lo = mid + 1;
      }
      #ifdef DEBUG
      puts("====");
      #endif
    }
    
    printf("Case #%d: %d\n", ctr+1, ans);
  }
  
  return 0;
}
