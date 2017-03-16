#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

int n;
int cnt[26];

void solve() {
  cin >> n;
  REP (i, n) cin >> cnt[i];

  for (;;) {
    int sum = 0;
    REP (i, n) sum += cnt[i];
    if (!sum)
      break;

    string ret;
    int v = 0;
    REP (i, n) if (cnt[i] > cnt[v]) v = i;
    cnt[v]--;
    sum--;
    ret += 'A' + v;

    bool ck = false;
    REP (i, n) if (cnt[i] * 2 > sum) ck = true;
    if (ck) {
      int v = 0;
      REP (i, n) if (cnt[i] > cnt[v]) v = i;
      cnt[v]--;
      sum--;
      ret += 'A' + v;
    }
    cout << ret << " ";
  }
  cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
