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
#define ll long longb
using namespace std;
 
const double PI = 2.0 * acos (0.0);
 
typedef long long LL;
typedef pair <int, int> PII;
 
template <class T> inline T MAX (T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN (T a, T b) { if (a < b) return a; return b; }

#define maxn 
#define X first
#define Y second

string a[111];
vector<char> list[111];
int num[111][111];

int main() {
    int ntest;
    cin >> ntest;
    FOR(test,1,ntest) {
        int n; cin >> n;
        FOR(i,1,n) cin >> a[i];
        FOR(i,1,n) {
            list[i].clear();
        }
        RESET(num, 0);

        FOR(i,1,n) REP(j, a[i].size()) {
            if (j==0 || a[i][j]!=a[i][j-1]) {
                list[i].PB(a[i][j]);
            }
            int t=list[i].size();
            num[i][t-1]++;
        }
        bool ok = true;
        
        FOR(i,2,n) if(list[i]!=list[i-1]) ok=false;
        
        cout << "Case #" << test <<": ";
        if (ok) {
            int t=list[1].size();
            int res=0;
            REP(j,t) {
                int best=1000111000;
                FOR(v,1,100) {
                    int tmp=0;
                    FOR(i,1,n)
                        tmp+=abs(v-num[i][j]);
                    if (tmp<best)
                        best=tmp;
                }
                res+=best;
            }
            cout << res <<endl;
        } else
            cout << "Fegla Won" << endl;
    }
}