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


#define mem(name,value) memset(name,value,sizeof(name))
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;

const int maxn = 1000;

int b[maxn],n,m,ans;

vector<int>idx;

bool check(long long time){
    idx.clear();
    long long sum = 0;
    for(int i=0;i<n;i++){
        sum += ceil(time / b[i] + eps);
        if(time % b[i]==0) idx.push_back(i+1);
    }
    if(sum >= m){
        long long sz = sum - idx.size();
        if(sz >= m) return true;
        long long tmp = m - sz;
        ans = idx[tmp-1];
        return true;
    }
    return false;
}


int main(){
    //freopen("in.txt","r",stdin);
    freopen("/Users/w/Desktop/in.txt", "r", stdin);
    freopen("/Users/w/Desktop/out.txt", "w", stdout);
    int T,kase=0;
    scanf("%d",&T);
    while(T--){

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        long long l = 0, r = (long long)m*1000;
        while(l<=r){
            long long mid = l+(r-l)/2;
            if(check(mid)) r = mid-1;
            else l = mid+1;
        }

        printf("Case #%d: %d\n",++kase,ans);
    }
    return 0;
}
