#include<cstring>
#include <cassert>
#include<stack>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<fstream>
#include<climits>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<iterator>
#include<map>
#include<sstream>
#include<set>
#include<limits>
#include<queue>

#ifdef h0me
#define FILES freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILES //freopen("cooling.in","r",stdin);freopen("cooling.out","w",stdout);
#endif

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long Long;
typedef long double Double;
namespace Helper
{
    template<typename T> inline string inttos(T x){ostringstream q;q << x;return q.str();}
    inline int stoint( string str){istringstream in(str);int res;in >> res;return res;}
    inline Long stolong(string str){istringstream in(str);Long res;in >> res;return res;}
    template<typename T> inline T pow(T x, T n, T MOD){T res = 1;while (n>0) {if (n & 1) {res = 1ll*res * x % MOD;}x = 1ll*x * x % MOD;n/=2;}return res;}
    template<typename T> inline T gcd(T a, T b){a=abs(a);b=abs(b);while ((a>0) && (b>0)) {if (a>b)a%=b;else b%=a;}return a+b;}
    inline int rand() { long long q = 1ll*rand()*RAND_MAX+rand(); return q % INT_MAX; }
    inline int abs(int x) { if (x<0) return -x;else return x; }
    const int MAXINT = 0x7FFFFFFF;
}


const Double EPS = 1e-10;
int a[111111];
int n;
Long f(int m, int pos)
{
    if (m<0)
        return -1;
    Long q = 0;
    Long t = m*1ll*a[pos];
    for (int i = 0; i < n; ++i) {
        Long w = t/a[i];
        if (t%a[i]>0)
            w++;
        else if (i<pos) { // t%a[i]==0
            w++;
        }
        q=q+w;
    }
    return q;
}
int main() {
    FILES;
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cout << "Case #" << test+1 << ": ";
        Long k;
        cin >> n >> k;
        for (int i = 0 ; i < n; ++i) {
            cin >> a[i];
        }
        int res = -1;
        k--;
        for (int i = 0; i < n; ++i) {
            int l = -1;
            int r = 1001000000;
            while (l+1<r) {
                int m = (l+r)>>1;
                if (f(m,i)<0ll+k) {
                    l = m;
                }
                else {
                    r = m;
                }
            }
            if (f(r,i)==k || f(r+1,i)==k || f(r-1,i)==k) {
                res = i+1;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
