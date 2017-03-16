#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
 
using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PDD pair<double, double>
#define PSS pair<string, string>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define prev eruyvuy
#define INF 2000000007
#define next abc
const double EPS = 1E-7;
const LL mod = 1000000007;

using namespace std;

LL n,pos;
LL a[1005];
LL ans;

bool aless(LL t) {
  LL tot = 0;
  FOR(i, n) {
    tot += t / a[i];
    if (t % a[i]) tot++; // in process
    if (tot >= pos) {
      //cout << "A " << t << ' '<< tot << endl;
      return false;
    }
  }

  //cout << t << ' ' << tot << endl;

  if (tot>=pos) return false;
  return 1;
}

void fig(LL t) {
  vector<int> fr;
  LL tot = 0;
  FOR(i, n) {
    tot += t / a[i];
    if (t % a[i]) tot++; // in process
    else fr.push_back(i);
  }
  assert(fr.size());
  FOR(i, fr.size()) {
    tot++;
    if (tot == pos) {
      ans = fr[i]+1;
      return;
    }
  }
  assert(0);
}

int main() {
  ios_base::sync_with_stdio(0);
  int t,idx=1;
  cin >> t;
  FOR(tt,t) {
    cin >> n >> pos;
    FOR(i, n) {
      cin >> a[i];
    }
    LL l = 0,mid;
    LL r = 100000000000005LL;

    while (r-l>1LL) {
      mid = (l+r)/2;
      if (aless(mid)) {
        l = mid;
      } else {
        r = mid;
      }
    }

    if (aless(r)) {
      fig(r);
    } else {
      fig(l);
    }

    cout << "Case #" << idx++ << ": " << ans << endl;
  }  

  return 0;
}
