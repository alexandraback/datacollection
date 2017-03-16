#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<cstring>
#include<algorithm>
#include <climits>
#include <cmath>
#include<cstdlib>
#include<cstdio>
#include <cctype>
#include<iostream>
#include<sstream>
#include<ctime>
#include <functional>
#include <numeric>
using namespace std;


#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define DEBUG if(0)
#define SZ(c) c.size()
#define ALL(x) x.begin(),x.end()
#define ff first
#define ss second
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PSI pair<string, int>
#define VI vector<int>
#define VS vector<string>
#define VVI vector< VI >
#define VPI vector< PII >
#define LL long long
#define ULL unsigned long long
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPR(i,n) for(int i=(int)n-1; i>=0; --i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)


template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }
template< class T > T GCD(const T a, const T b) { return (b ? GCD<T>(b, a%b) : a); }
template< class T > T LCM(const T a, const T b) { return (a / GCD<T>(a, b) * b); }
template< class T > T mod(const T &a, const T &b) { return (a < b ? a : a % b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }

const int INF=1000000007;
const int MOD=1000000007;
const LL LINF = 1ll << 60;


int main()
{
   READ("in.txt");
   WRITE("out.txt");

   int tc, r, c, n;
   int res;

   cin>>tc;

   for(int cs=1; cs<=tc; cs++)
   {

       cin>>r>>c>>n;
       int mx=(r*c);
       res=INF;
       int maxn=(((r+1)/2)*((c+1)/2))+((r/2)*(c/2));
       if(n<=maxn)
       {
           cout<<"Case #"<<cs<<": "<<0<<endl;
           continue;
       }
       for(int mask=0; mask<(1<<mx); mask++)
       {
           int cnt=0;
           for(int i=0; i<mx; i++)
           if(mask & (1<<i)) cnt++;

           bool grid[r][c];
           for(int i=0; i<r; i++)
           for(int j=0; j<c; j++)
           grid[i][j]=false;

           if(cnt==n)
           {
               for(int i=0; i<r; i++)
               {
                   for(int j=0; j<c; j++)
                   {
                       int idx=j+(i*c);
                       if(mask & (1<<idx)) grid[i][j]=true;
                   }
               }

               int nres=0;
               for(int i=0; i<r; i++)
               {
                   for(int j=0; j<c; j++) if(grid[i][j])
                   {
                       if(i+1<r && grid[i+1][j]) nres++;
                       if(j+1<c && grid[i][j+1]) nres++;
                   }
               }

               res=min(res, nres);

           }
       }

       cout<<"Case #"<<cs<<": "<<res<<endl;
   }

   return 0;
}





