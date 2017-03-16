
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <bitset>
#include <sstream>
#include <string.h>
using namespace std;

#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second

#if ( _WIN32 || __WIN32__ )
   #define LLD "%I64d"
#else
   #define LLD "%lld"
#endif

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename T> T abs(T a) { return a < 0 ? -a : a; }
template<typename T> T sqr(T a) { return a*a; }

const int INF = (int)1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;


const int NMAX = 300000;
const int LOG = 20;
const int mod = 1000000000 + 7;

int n, q, root, used[NMAX];
vector<int> g[NMAX];
int dep[NMAX], p[NMAX][LOG], lf[NMAX], rg[NMAX], mul[3][NMAX], timer = 0;

void dfs(int v, int pv){
   used[v] = 1;
   dep[v] = (v == pv ? 0 : dep[pv] + 1);
   lf[v] = rg[v] = timer++;

   p[v][0] = pv;
   fore(lev, 1, LOG){
       p[v][lev] = p[p[v][lev - 1]][lev - 1];
   }

   forn(i, sz(g[v])){
       int u = g[v][i];
       if(u == pv)
           continue;
       dfs(u, v);
       rg[v] = rg[u];
   }
}

int lca(int a, int b){
   if(dep[a] < dep[b])
       swap(a, b);
   forn(i, LOG){
       if((dep[a] - dep[b]) & (1 << i)){
           a = p[a][i];
       }
   }
   for(int i = LOG - 1; i >= 0; --i){
       if(p[a][i] != p[b][i]){
           a = p[a][i];
           b = p[b][i];
       }
   }
   if(a != b)
       a = p[a][0], b = p[b][0];
   assert(a == b);
   return a;
}

inline void norm(int& v){
   while(v < 0)
       v += mod;
   while(v >= mod)
       v -= mod;
}

int modpow(int a, int b){
   int ans = 1 % mod;
   while(b){
       if(b & 1)
           ans = (ans * li(a)) % mod;
       a = (a * li(a)) % mod;
       b >>= 1;
   }
   return ans;
}

inline int rev(int a){
   return modpow(a, mod - 2);
}

inline int doMod(li v){
   return (int)((v % mod + mod) % mod);
}

void upd(int t[NMAX], int i, int v){
   for(; i < NMAX; i = (i | (i + 1))){
       t[i] += v;
       norm(t[i]);
   }
}

int sum(int t[NMAX], int r){
   int ans = 0;
   for(; r >= 0; r = (r & (r + 1)) - 1){
       ans += t[r];
       norm(ans);
   }
   return ans;
}

int sum(int t[NMAX], int l, int r){
   int ans = sum(t, r) - sum(t, l - 1);
   norm(ans);
   return ans;
}

int get(int a){
   int pw = 1, ans = 0;
   forn(i, 3){
       ans = (ans + sum(mul[i], 0, lf[a]) * 1LL * pw) % mod;
       pw = (pw * 1LL * dep[a]) % mod;
   }
   return ans;
}

int dist(int a, int b){
   int mid = lca(a, b);

   int ans = get(a) + get(b) - 2 * get(mid);
   norm(ans);
   if(mid == root)
       ans += get(mid);
   else
       ans += get(mid) - get(p[mid][0]);
   norm(ans);
   return ans;
}

void rangeupd(int t[NMAX], int l, int r, int val){
   upd(t, l, val);
   upd(t, r + 1, doMod(mod - val));
}

void doUpdQuery(int t, int V, int U){
   int L = lf[t], R = rg[t], x = V;
   rangeupd(mul[0], L, R, doMod((1 - dep[t]) * li(x)));
   rangeupd(mul[1], L, R, x);
   x = U;
   rangeupd(mul[0], L, R, doMod(-(1 - dep[t]) * 1LL * doMod(x * 1LL * dep[t])));
   rangeupd(mul[1], L, R, doMod(-x * 1LL * dep[t]));

   rangeupd(mul[1], L, R, doMod(-x * 1LL * dep[t] + x));
   rangeupd(mul[2], L, R, x);
   x = doMod(-x * 1LL * rev(2));
   rangeupd(mul[0], L, R, doMod(((dep[t] * 1LL * dep[t] - dep[t]) % mod) * li(x)));
   rangeupd(mul[1], L, R, doMod((-2 * dep[t] + 1) * li(x)));
   rangeupd(mul[2], L, R, x);
}

int main(){
    
    //while(~scanf("%d%d",&n,&q))
    scanf("%d%d",&n,&q)
    {
        memset(dep,0,sizeof(dep));
        memset(p,0,sizeof(p));
        memset(lf,0,sizeof(lf));
        memset(mul,0,sizeof(mul));
        memset(rg,0,sizeof(rg));
        memset(used,0,sizeof(used));
        for (int i=0;i<NMAX;i++) g[i].clear();
        scanf("%d",&root);
        root--;
         forn(i, n - 1){
           int a, b;
           scanf("%d%d",&a,&b);
           a--,b--;
           g[a].pb(b);
           g[b].pb(a);
       }

       dfs(root, root);
       forn(v, n){
           assert(used[v]);
       }

       forn(qi, q){
           char type;
           assert(scanf(" %c ", &type) == 1);
           assert(type == 'Q' || type == 'U');
           if(type == 'Q'){
                int a, b;
                scanf("%d%d",&a,&b);
                a--,b--;
                printf("%d\n", dist(a, b));
           }else{
                int t, v, k;
                scanf("%d%d%d",&t,&v,&k);
                t--,v--,k--;
                doUpdQuery(t, v, k);
           }
       }
    }  
    return 0;
}