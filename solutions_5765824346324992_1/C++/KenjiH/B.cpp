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

int b, n;
int m[1000];

long long calc(long long t) {
    long long ret = 0;
    REP (i, b) ret += (t + m[i] - 1) / m[i];
    return ret;
}

void solve() {
    cin >> b >> n;
    REP (i, b) cin >> m[i];

    long long hi = 1LL<<50;
    long long lo = -1;

    while (hi - lo > 1) {
        long long mi = (hi + lo) / 2;
        if (calc(mi) >= n)
            hi = mi;
        else
            lo = mi;
    }

    --hi;
    REP (i, b) n -= (hi + m[i] - 1) / m[i];

    int ret = 0;
    REP (i, b) {
        if (hi % m[i] == 0) {
            if (--n == 0) {
                ret = i;
                break;
            }
        }
    }
    
    cout << ++ret << endl;
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
