#include "cstdio"
#include "iostream"
#include "algorithm"
#include "cmath"
#include "cstring"
#include "cstdlib"
#include "climits"
#include "cassert"
#include "bitset"
#include "complex"
#include "queue"
#include "vector"
#include "queue"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MK make_pair
#define X first
#define Y second
#define ll long long
#define ull unsigned long long
#define ITR iterator
#define LB lower_bound
#define UB upper_bound
#define PII pair<int, int>
#define CLR(a) memset(a, 0, sizeof(a))
int getint(){
    int s = 0, o = 1;
    char c;
    for(c = getchar(); c<'0'||c>'9';c = getchar()) if(c=='-') o = -1;
    for(;c>='0'&&c<='9'; c = getchar()) s *=10, s+=c-'0';
    return s*o;
}
  
const int maxn = 100010;
long long n, m, k;
long long run2(ll n, ll m, ll k){
    if(n%2==0 || m%2==0) return n*m*4;
    ll N = n/2, M = m/2;
    ll all = N*(M+1) + (N+1)*M;
    if(k<=all) return 0;
    if(k<=all + 4) return 2 * (k - all);
    k -= all + 4;
    ll c3 = 2 * (n - N - 2 + m - M - 2);
    if(k<=c3) return 2 * 4 + 3 * k;
    return 2 * 4 + 3 * c3 + 4 * (k - c3);
}
long long run(ll n, ll m, ll k){
    if(n==1){
        if(k<=(m+1)/2) return 0;
        k -= (m+1)/2;
        if(m%2==0)
            return 1 + (k-1)*2;
        return k * 2;
    }
    if(n%2==1){
        if(m%2==1){
            ll N = (n+1)/2, M = (m+1)/2;
            ll all = N*M + (N-1)*(M-1);
            if(k <= all) return 0;
            ll c3 = 2 * (N-1 + M-1);
            if(k <= all + c3) return (k - all) * 3;
            return c3 * 3 + (k - all - c3) * 4;
        }else{
            ll N = (n+1)/2, M = m/2;
            ll all = N*M + (N-1)*M;
            if(k<=all) return 0;
            if(k<=all + 2) return 2 * (k - all);
            k -= all + 2;
            ll c3 = 2 * (M-1) + N - 1 + N - 2;
            if(k<=c3) return 2 * 2 + 3 * k;
            return 2 * 2 + 3 * c3 + 4 * (k-c3);
        }
    }else{
        ll N = n/2, M = m/2;
        ll all = N*M*2;
        if(k <= all) return 0;
        if(k <= all + 2) return 2 * (k - all);
        k -= all + 2;
        ll c3 = 2 * (N-1 + M-1);
        if(k <= c3) return 2 * 2 + 3 * k;
        return 2 * 2 + 3 * c3 + 4 * (k - c3);
    }
}
int main(int argc, char const *argv[])
{   
    int cas = getint();
    rep(ca,cas){
        cin >> n >> m >> k;
        if(n>m) swap(n, m);
        if(n%2==0) swap(n, m);
        printf("Case #%d: %lld\n", ca+1, min(run(n, m, k), run2(n,m,k)));
    }
    return 0;
}