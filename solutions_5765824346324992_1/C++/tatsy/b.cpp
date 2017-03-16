#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <list>
#include <stack>
#include <tuple>
#include <utility>
#include <complex>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <typeinfo>
using namespace std;

typedef long long lint;
typedef pair<int,int> pii;
typedef pair<lint,lint> pll;

#define REP(i,n) for(int i=0; i<(n); i++)
#define REPA(i,s,e) for(int i=(s); i<=(e); i++)
#define REPD(i,s,e) for(int i=(s); i>=(e); i--)
#define ALL(a) (a).begin(), (a).end()

#define PRT(a) cerr << #a << " = " << (a) << endl
#define PRT2(a, b) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << endl
#define PRT3(a, b, c) cerr << #a << " = " << (a) << ", " << #b << " = " << (b) << ", " << #c << " = " << (c) <<  endl
template <class Ty> void print_all(Ty b, Ty e) {
	cout << "[ ";
	for(Ty p=b; p!=e; ++p) {
		cout << (*p) << ", ";
	}
	cout << " ]" << endl;
}

// -----------------------------------------------------------------------------
// Code starts 
// -----------------------------------------------------------------------------

int N, B;
lint M[1011];

lint gcd(lint x, lint y) {
    if (x < y) swap(x, y);
    while (y != 0) {
        lint t = x % y;
        x = y;
        y = t;
    }
    return x;
}

lint lcm(lint x, lint y) {
    return x / gcd(x, y) * y;
}

lint calc(lint x) {
    lint ret = 0;
    REP(i, B) {
        ret += x / M[i] + 1;
    }
    return ret;
}

void solve() {
    cin >> B >> N;
    REP(i, B) cin >> M[i];

    lint lo = 0;
    lint hi = 1ll << 40;
    while (lo < hi) {
        lint mid = (lo + hi) / 2;
        if (calc(mid) < N) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }

    lint t = lo;
    lint tot = 0;
    vector<int> v;
    REP(i, B) {
        tot += lo / M[i] + 1;
        if (lo % M[i] == 0) v.push_back(i + 1);
    }

    int k = v.size() - (int)(tot - N) - 1;
    cout << v[k] << endl;
}

// -----------------------------------------------------------------------------
// Code ends 
// -----------------------------------------------------------------------------

void coding() {
    int T;
    cin >> T;
    REPA(t,1,T) {
        fprintf(stderr, "%3d / %d\n", t, T);
        printf("Case #%d: ", t);
        solve();
    }
}

#define _LOCAL_TEST 2

int main() {
#if _LOCAL_TEST == 0
	clock_t startTime = clock();
	freopen("b.in", "r", stdin);
#elif _LOCAL_TEST == 1
	freopen("../input/B-small-attempt0.in", "r", stdin);
    freopen("../input/B-small0.out", "w", stdout);
#elif _LOCAL_TEST == 2
	freopen("../input/B-large.in", "r", stdin);
    freopen("../input/B-large.out", "w", stdout);
#endif

	coding();

#if _LOCAL_TEST == 0
	clock_t elapsedTime = clock() - startTime;
	cerr << endl;
	cerr << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cerr << "This is local test" << endl;
	cerr << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif

}
