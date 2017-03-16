#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());

int t, n, a[2000];

int main(){
  ri(t);
  for (int T = 1; T <= t; T++) {
    ri(n);
    for (int i = 0; i < n; i++) ri(a[i]);
    int r1, r2, maxDiff = 0;
    r1 = r2 =0;
    for (int i = 1; i < n; i++) {
      if (a[i-1] > a[i]) {
        r1 += (a[i-1]-a[i]);
        maxDiff = max(maxDiff, a[i-1]-a[i]);
      }
    }
    for (int i = 0; i < n-1; i++) {
      r2 += min(a[i], maxDiff);
    }
    printf("Case #%d: %d %d\n", T, r1, r2);
    
  }
  
  return 0;
}
