#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <fstream>
#include <ctime>
#include <iomanip>
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FO(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOD(i,a,b) for(int i=a;i>b;i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define debug cout << "YES" << endl
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef pair<int, int>II;
typedef pair<int,II>PII;
template<class T> T gcd(T a, T b) {T r; while(b!=0) {r=a%b;a=b;b=r;} return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }

const double PI = 2*acos(0.0);
const double eps = 1e-15;
const int infi = 1e9;
const LL Linfi = (LL) 1e18;
const LL MOD = 1000000007;
const int c1 = 31;
const int c2 = 37;
#define maxn 1000005

int n, m, k, res = infi;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void check(vector<int> V){
    set<II> S;
    FO(i,0,V.size()){ //cout << V[i] << endl;
        int x = V[i]/m;
        int y = V[i]%m;
        if(V[i]%m == 0) { y = m; }
        else x++;
         //cout << x << " " << y << endl;
        S.insert(II(x,y));
    }
    int ans = 0;
    FORV(i,S){
        II tmp;
        FOR(k,0,3){
            tmp.fi = i->fi+dx[k];
            tmp.se = i->se+dy[k];
            if(S.find(tmp) != S.end()) ans++;
        }

    }
    res = min(res, ans/2);
}

void solve(){
    res = infi;
    int x = n*m;
    int last = (1<<x)-1; //cout << __builtin_clz(last) << endl;
    FOR(mask,1,last){
        if(__builtin_popcount(mask) == k) {
            vector<int> V;
            FOR(i,1,x){
                if(getbit(mask, i-1)) V.pb(i);
            }
            check(V);
        }
    }
    if(res == infi) res = 0;
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    int sotest;
    cin >> sotest;
    FOR(test,1,sotest){
        cin >> n >> m >> k;
        cout << "Case #" << test << ": ";
        solve();
    }



    return 0;
}


