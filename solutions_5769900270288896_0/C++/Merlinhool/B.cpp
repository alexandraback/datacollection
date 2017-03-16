#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
int _;
int f[20][20][20];
int idx[20][20];
int stk[22], pp[1<<17];
std::pair<int, int> pos[20];
bool check(std::pair<int, int> a, std::pair<int, int> b) {
        if(a.first == b.first && abs(a.second - b.second) == 1) return 1;
        if(a.second == b.second && abs(a.first - b.first) == 1) return 1;
        return 0;
}
int solve(int n, int m, int K) {
        int &ret = f[n][m][K];
        if(~ret) return ret;
        int N = 0;
        for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                        pos[N].first = i;
                        pos[N].second = j;
                        idx[i][j] = N++;
                }
        }

        ret = ~0u>>1;
        for(int i = 0, j, k, t; i < (1 << N); ++i) if(__builtin_popcount(i) == K){
                int cnt = 0, r = 0;
                for(j = i; j; j ^= t) {
                        t = j & (-j);
                        stk[r++] = pp[t];
                }

                for(j = 0; j < r; ++j) {
                        for(k = j+1; k < r; ++k) if(check(pos[stk[j]], pos[stk[k]])) ++cnt;
                }
                chmin(ret, cnt);
        }
        return ret;
}
int main() {
        freopen("a.out","w",stdout);
        memset(f, -1, sizeof f);
        for(int i = 1, j = 0; j <= 16; ++j, i <<= 1) pp[i] = j;

        int n, m, K;
        for(scanf("%d", &_); _--; ) {
                scanf("%d%d%d", &n, &m, &K);
                static int cas = 0;
                printf("Case #%d: %d\n", ++cas, solve(n, m, K));
        }
        return 0;
}
