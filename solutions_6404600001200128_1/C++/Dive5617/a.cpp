//#pragma comment(linker,"/STACK:102400000,102400000")
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
 
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())    if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())    x = x * 10 + ch - '0';
    return positive ? x : -x;
}

inline char RC (){
    char c = getchar ();
    while (c == ' '||c == '\n')     c = getchar ();
    return c;
}

inline LL gcd(LL a, LL b) {return b?gcd(b, a%b):a;}

inline LL lcm(LL a, LL b) {return a * b / gcd(a, b);}

inline LL Sub(LL x, LL y, LL mod){
    LL res = x - y;
    while(res < 0) res += mod; 
    return res;
}

inline LL Add(LL x, LL y, LL mod){
    LL res = x + y;
    while(res >= mod)  res -= mod;
    return res;
}

inline LL POW_MOD(LL x, LL y, LL mod){
    LL ret = 1;
    while(y > 0){
        if(y & 1)  ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

/****************************define***************************************/

const int N = 1005 + 100;
const int M = 400000 + 100;
const LL INF = 9e18;
const int inf = 0x7fffffff;
const LL MOD = 100007;
const double PI = acos(-1.0);
const double G = 9.8;
const double eps = 1e-3;

int n, m, a, b;

vector<PII> aa, bb;

LL dis(PII x, PII y){
    return (x.FF - y.FF) * (x.FF - y.FF) + (x.SS - y.SS) * (x.SS - y.SS);
}

LL calc_f(LL x, LL sum1, LL sum2){
    return a * x * x + (sum1 + 1) * x + sum2;
}


void calc(PII x, PII y, LL &sum1, LL &sum2, LL &sum3, LL &sum4){
    sum1 += 2 * (x.FF - y.FF);
    sum2 += (LL)(x.FF - y.FF) * (x.FF - y.FF);
    sum3 += 2 * (x.SS - y.SS);
    sum4 += (LL)(x.SS - y.SS) * (x.SS - y.SS);
}

LL solve(){
    LL ans = INF;
    for(int i = 0; i < b; ++ i){
        PII now = bb[i];
        LL sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        LL res = 0;
        for(int j = 0; j < a; ++ j){
            calc(now, aa[j], sum1, sum2, sum3, sum4);
        }
        LL mid1 = -1 * (sum1 + 1) / (2 * a), mid2 = -1 * (sum3 + 1) / (2 * a);
        if(mid1 >= 0) res += calc_f(mid1, sum1, sum2);
        else          res += sum2;
        if(mid2 >= 0) res += calc_f(mid2, sum3, sum4);
        else          res += sum4;
        cout << "ss" << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
        //cout << mid1 << " " << mid2 << " " << res << "he" << endl;
        ans = min(ans, res);
        if(ans == 13){
            cout << "he" << endl;
            cout << sum3 << " " << sum4 << endl;
            cout << calc_f(mid1, sum1, sum2) << " " << calc_f(mid2, sum3, sum4) << endl;
            cout << mid1 << " " << mid2 << endl;
        }
    }
    return ans;
}

int main(){
    int T, Cas = 1;
    cin >> T;
    while(T --){
        aa.clear(), bb.clear();
        n = read(), m = read(), a = read(), b = read();
        for(int i = 0; i < a; ++ i){
            int x, y; x = read(), y = read();
            aa.PB(MP(x, y));
        }
        for(int i = 0; i < b; ++ i){
            int x, y; x = read(), y = read();
            bb.PB(MP(x, y));
        }
        printf("Case #%d: %lld\n", Cas++, solve());
    }
    return 0;
}