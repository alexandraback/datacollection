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

int N;
int m[10000];

void solve() {
    cin >> N;
    REP (i, N) cin >> m[i];

    int x1 = 0;
    int x2 = 0;

    for (int i = 1; i < N; i++) {
        x1 = x1 + max(0, m[i-1] - m[i]);
    }

    int y = 0;
    for (int i = 1; i < N; i++) {
        y = max(y, m[i-1] - m[i]);
    }

    for (int i = 0; i + 1 < N; i++) {
        x2 = x2 + min(m[i], y);
    }

    cout << x1 << " " << x2 << endl;

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
