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

struct point {
    int64 x, y;
    int id;

    explicit point(int64 x = 0, int64 y = 0) : x(x), y(y) {}

    point operator - (const point &p) const {
        return point(x - p.x, y - p.y);
    }

    bool operator < (const point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

int64 vmul(const point &a, const point &b) {
    return a.y*b.x - a.x*b.y;
}

int64 dist2(const point &a, const point &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

long double dist(const point& a, const point& b) {
    return sqrt(1.0 * dist2(a, b));
}

bool on(const point& a, const point& b, const point& x) {
    return abs(dist(a, b) - dist(x, b) - dist(x, a)) < EPS;
}

struct cmp {
    point c;

    explicit cmp(point c) : c(c) {}

    bool operator () (const point &a, const point &b) const {
        int64 v = vmul(a - c, b - c);
        return v > 0 || (v == 0 && dist2(c, a) < dist2(c, b));
    }
};

vector<point> convex(vector<point> a) {
    if (a.size() <= 3) return a;
    swap (a[0], *min_element(all(a)));
    sort (a.begin() + 1, a.end(), cmp(a[0]));

    vector<point> ans;
    forn(i, a.size()) {
        while (ans.size() > 1 && vmul(ans.back() - ans[ans.size() - 2], a[i] - ans[ans.size() - 2]) <= 0) {
            ans.pop_back();
        }

        ans.pb(a[i]);
    }

    vector<point> res;
    forn(i, a.size()) {
        bool ok = false;
        forn(j, ans.size()) {
            if (on(ans[j], ans[(j + 1) % ans.size()], a[i])) {
                ok = true;
                break;
            }
        }

        if (ok) {
            res.pb(a[i]);
        }
    }

    return res;
}

point a[MAXN];
int n;

vector<int> stupid() {
    vector<int> ans(n, INF);
    forn(mask, 1 << n) {
        vector<point> aa;
        forn(i, n) {
            if (bit(mask, i)) {
                aa.pb(a[i]);
            }
        }

        vector<point> c = convex(aa);
        forn(i, c.size()) {
            int v = c[i].id;
            ans[v] = min(ans[v], n - int(aa.size()));
        }
    }

    return ans;
}

void solve(bool skipThisTest) {
    if (true) {
        cerr << "\tinput mode: read test." << endl;
        n = nextInt();
        forn(i, n) {
            a[i].x = nextInt();
            a[i].y = nextInt();
            a[i].id = i;
        }
        if (skipThisTest) return;
    } else {
        cerr << "\tinput mode: generated test." << endl;
        n = rand() % 15 + 1;
        forn(i, n) {
            a[i].x = rand() % 100;
            a[i].y = rand() % 100;
            a[i].id = i;
        }
    }

    vector<int> ans = stupid();

    cout << endl;
    forn(i, n) {
        cout << ans[i] << endl;
    }

    cerr << "\tclever answer is '" << ans.size() << "'." << endl;
    if (n <= 15) {
        vector<int> stupidAnswer = stupid();
        cerr << "\tstupid answer is '" << stupidAnswer.size() << "'." << endl;
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
