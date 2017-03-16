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


int main() {
    freopen("a.in","r",stdin);
    freopen("a.out", "w", stdout);
    ios::sync_with_stdio(false);
    int _;
    cin >> _;
    FOR(test, 1, _) {
        vector<int> res;
        int r1, r2, a[5][5], b[5][5];
        cin >> r1;
        FOR(i, 1, 4) FOR(j, 1, 4) cin >> a[i][j];
        cin >> r2;
        FOR(i, 1, 4) FOR(j, 1, 4) cin >> b[i][j];
        FOR(i, 1, 4) FOR(j, 1, 4) if (a[r1][i] == b[r2][j]) res.PB(a[r1][i]);
        cout << "Case #" << test << ": ";
        if (res.size() == 0) {
            cout << "Volunteer cheated!" << endl;
        } else if (res.size() == 1) {
            cout << res[0] << endl;
        } else {
            cout << "Bad magician!" << endl;
        }
    }
    return 0;
}
