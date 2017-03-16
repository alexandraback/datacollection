//Written by technolt~h
 
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
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
 
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define ll long long
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 

int main() {
	freopen("a.inp","r",stdin);
	freopen("a.out","w",stdout);
	int _; cin >> _;
	FOR(test, 1, _) {
        int row[2], a[2][4][4];
        REP(t, 2) {
            cin >> row[t];
            REP(i, 4) REP(j, 4) cin >> a[t][i][j];
        }
        vector<int> sol;
        FOR(v, 1, 16) {
            int ok = 0;
            REP(t, 2) REP(j, 4) if (a[t][row[t] - 1][j] == v) ok |= 1 << t;
            if (ok == 3) sol.PB(v);
        }
        cout << "Case #" << test << ": ";
        if (sol.size() == 0)
            cout << "Volunteer cheated!" << endl;
        else if (sol.size() > 1)
            cout << "Bad magician!" << endl;
        else
            cout << sol[0] << endl;
	}
}

