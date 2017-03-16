#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define forin(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> inline bool Min(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> inline bool Max(T &a, T b) { return a < b ? (a = b, true) : false; }

inline int    ni() { int    a; scanf("%d",   &a); return a; } // next_int();
inline ll     nl() { ll     a; scanf("%lld", &a); return a; } // next_long();
inline double nd() { double a; scanf("%lf",  &a); return a; } // next_double();

inline void pi(int    a) { printf ( "%d ",      a); }
inline void pl(ll     a) { printf ( "%lld ",    a); }
inline void pd(double a) { printf ( "%.12lf ",  a); }
///////////////////////////////////////////////////////////////////////////////


void solve(int test)
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    
    set<pair<int, char>> m;
    forn(i, n) m.insert(mp(a[i], 'A' + i));
    
    int sum = 0;
    forn(i, n) sum += a[i];
    
    vector<string> xs;
    
    while ( sum )
    {
        pair<int, char> v = *m.rbegin();
        m.erase(v);
        
        string s;
        
        s.push_back(v.second);
        m.insert(mp(v.fi - 1, v.se));
        sum--;
        
        if ( sum )
        {
            if ( m.rbegin()->first * 2 > sum ){
                v = *m.rbegin();
                s.push_back(m.rbegin()->second);
                m.erase(v);
                m.insert(mp(v.fi - 1, v.se));
                sum--;
            }
            else
            {
                
            }
        }
        
        xs.push_back(s);
    }
    
    cout << "Case #" << test << ": ";
    for(string s : xs) cout << s << " ";
    cout << "\n";
}

void solve()
{
    int t;
    cin >> t;
    
    forn(i, t) solve(i+1);
}

int main()
{
#define GCJ

    
#ifdef LOCAL
#ifdef GCJ
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);
#endif
#endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand((int)clock());
    
    solve();
    
    return 0;
}