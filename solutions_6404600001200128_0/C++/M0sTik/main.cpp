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
int a[1111111];
int n;
int f(int m)
{
    int res = 0;
    int o = 0;
    for (int i = 0; i < n; ++i) {

        if (o>a[i])
            return -1;
        if (i==n-1) {
            return res;
        }
        o = a[i];
        res = res+min(m,o);
        o = o-m;
        if (o<0)
            o = 0;
    }
    return -1;
}
int main() {
    FILES;
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int test = 0; test < tests; ++test) {
        cout << "Case #" << test+1 << ": ";
        cin >> n;
        for (int i = 0 ; i < n; ++i) {
            cin >> a[i];
        }
        int res1 = 0;
        int res2 = 1000000000;

        for (int i = 1; i < n; ++i) {
            if (a[i]<a[i-1]) {
                res1 += a[i-1]-a[i];
                //cout << a[i] << " " << a[i-1] << " " <<res1 << endl;
            }
            else {
                //cout << a[i] << " " << a[i-1] << endl;
            }
        }
        //cout << f(9) << endl;
        for (int i = 0; i < 100000; ++i) {
            int q = f(i);
            if (q!=-1 && q<res2)
                res2 = q;
        }
        cout << res1 << " " << res2 << endl;
    }
    return 0;
}
