#ifdef NALP_PROJECT
#pragma hdrstop
#else
#define _SECURE_SCL 0
#endif

#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:200000000")

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cassert>

#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <bitset>
#include <memory.h>

#include <iostream>
#include <fstream>
#include <sstream>

#ifdef _WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define y1 YYY1
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> inline T Abs(T x) { return (x >= 0) ? x : -x; }
template<typename T> inline T sqr(T x) { return x * x; }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int bit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }

inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline int64 nextInt64() { int64 x; if (scanf(LLD, &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }

const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;

const int MAXN = 100100;

int n, a[MAXN], k;

int64 get(int64 t) {
    if (t < 0) {
        return 0;
    }

    if (t == 0) {
        return n;
    }

    int64 ans = 0;
    forn(i, n) {
        ans += max(0LL, t / a[i]) + 1;
        ans = min(ans, INF64);
    }

    return ans;
}

int stupid() {
    int last = -1;
    vector<int64> b(n, 0);
    forn(step, k) {
        int best = 0;
        forn(i, n) {
            if (b[best] > b[i]) {
                best = i;
            }
        }
        b[best] += a[best];
        last = best;
    }

    return last;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
        k = nextInt();
        forn(i, n) {
            a[i] = nextInt();
        }
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        n = rand() % 50 + 1, k = rand() % 100000 + 1;
        forn(i, n) {
            a[i] = rand() % 10 + 1;
        }
    }

    int64 l = 0, r = INF64;
    while (r - l > 1) {
        int64 mid = (l + r) >> 1;
        if (get(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }

    int64 t = -1;
    for(int64 mid = l; mid <= r; ++mid) {
        if (get(mid) >= k) {
            t = mid;
            break;
        }
    }

    if (t < 0) {
        cerr << n << " " << k << endl;
        forn(i, n) {
            cerr << a[i] << " ";
        }
        cerr << endl;
    }
    assert(t >= 0);

    vector<int> c;
    forn(i, n) {
        if (t % a[i] == 0) {
            c.pb(i);
        }
    }
    int pos = int(k - get(t - 1) - 1);
//    cerr << "t = " << t << endl;
//    cerr << "c = " << c.size() << " pos = " << pos << endl;

    if (pos < 0 || pos >= int(c.size())) {
        cerr << n << " " << k << endl;
        forn(i, n) {
            cerr << a[i] << " ";
        }
        cerr << endl;
    }

    assert(0 <= pos && pos < int(c.size()));

    int ans = c[pos];

    cout << ans + 1 << endl;

    cerr << "\tclever answer is '" << ans << "'." << endl;
    if (1LL * n * k <= 10*1000*1000) {
        int stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer << "'." << endl;
        assert(ans == stupidAnswer);
    }
}

int main(int argc, char * argv[]) {
#ifdef NALP_PROJECT
    freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
#else
#endif

    int minTest = 1, maxTest = INF;
    if (argc == 3) {
        minTest = atoi(argv[1]);
        maxTest = atoi(argv[2]);
    }

    cout.precision(10);
    cout.setf(ios::fixed);

    cerr.precision(10);
    cerr.setf(ios::fixed);

    srand((unsigned int)time(0));
    int tests = nextInt();
    clock_t totalStartTime = clock();
    for(int test = 1; test <= tests; test++) {
        clock_t startTime = clock();
        cerr << "Case #" << test << endl;
        bool skipThisTest = (test < minTest || test > maxTest);
        if (!skipThisTest) cout << "Case #" << test << ": ";
        solve(skipThisTest);

        char formattedTime[100];
        clock_t time = clock() - startTime;
        sprintf(formattedTime, "%d.%03d", int(time / CLOCKS_PER_SEC), int(time % CLOCKS_PER_SEC));
        cerr << "time for test is " << formattedTime << " s." << endl << endl;
    }

    char formattedTime[100];
    clock_t totalTime = clock() - totalStartTime;
    sprintf(formattedTime, "%d.%03d", int(totalTime / CLOCKS_PER_SEC), int(totalTime % CLOCKS_PER_SEC));
    cerr << string(20, '=') << endl;
    cerr << "TOTAL TIME IS " << formattedTime << " s." << endl;

    return 0;
}
