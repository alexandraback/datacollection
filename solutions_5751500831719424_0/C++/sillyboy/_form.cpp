#pragma comment(linker, "/STACK:16777216")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))

#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
#define SZ(a) ((int)a.size())
using namespace std;

const double PI = 2.0 * acos (0.0);

typedef pair <int, int> PII;

template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

int n;
string a[105];
int b[105][105];

string shrink(string x) {
    string res = "";
    char last = '$';
    REP(i, x.length()) if (res == "" || x[i] != last) {
        res += x[i];
        last = x[i];
    }
    return res;
}

void make(string x, int index) {
    string res = "";
    char last = '$';
    int cnt = 0;
    REP(i, x.length()) if (res == "" || x[i] != last) {
        if (cnt) b[res.length() - 1][index] = cnt;
        res += x[i];
        last = x[i];
        cnt = 1;
    } else cnt++;
    b[res.length() - 1][index] = cnt;
}

void process() {
    string x = shrink(a[1]);
    FOR(i, 1, n) if (shrink(a[i]) != x) {
        cout << "Fegla Won" << endl;
        return;
    }
    FOR(i, 1, n) make(a[i], i);
    int res = 0;
    REP(i, x.length()) {
        sort(b[i], b[i] + n + 1);
        FOR(j, 1, n) res += abs(b[i][j] - b[i][(n+1)/2]);
    }
    cout << res << endl;
}

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    FOR(test, 1, _) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        process();
    }
    return 0;
}
