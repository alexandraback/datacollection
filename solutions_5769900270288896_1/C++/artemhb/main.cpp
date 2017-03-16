// https://pp.vk.me/c540102/v540102394/7cd5/J2NXxBbvBrM.jpg
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
//#include <array>
//#include <unordered_set>
//#include <unordered_map>
#include <cassert>
#include <iomanip>
#define mp make_pair
#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define FORA(e,c) for(auto &e:c)
#define REP(i,n) FOR(i,0,n)
#define CL(x) memset(x, 0, sizeof(x))
#define SINF(x) memset(x, 0x3F, sizeof(x))
#define SVAL(x, y) memset(x, y, sizeof(x))
#define CP(t, f) memcpy(t, f, sizeof(f));
#define CPS(t, f, s) memcpy(t, f, s*sizeof(f[0]))
#define ALL(a) (a).begin(), (a).end()
#define ALLR(a) (a).rbegin(), (a).rend()
#define FIN freopen("in.txt", "r", stdin);
#define FINOUT freopen("in.txt", "w", stdout);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 ____y1
using namespace std;
typedef const int CI;
typedef long long ll;
typedef unsigned long long ull;
// typedef __float128 ld;
// typedef long double ld;
typedef double ld;
typedef vector<int> VINT;
typedef vector<ld> VLD;
typedef vector<ll> VLL;
typedef vector<vector<int> > VVINT;
typedef set<int> SI;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<ll, ll> PLL;
typedef pair<ld, ld> PLD;
typedef pair<ld, ld> ptp;
typedef complex<ld> Cn;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PIII> VPIII;
typedef vector<PLD> VPLD;
typedef set<PII> SII;
#include <array>
template <int n> using AI=array<int, n>; typedef AI<2> AII; typedef AI<3> AI3; typedef AI<4> AI4;
typedef unsigned int uint;
const ld eps=1e-9;
const int oo=0x3F3F3F3F;
const ll ooLL=0x3F3F3F3F3F3F3F3FLL;
const int MOD=1000000007;
template<typename T> T sqr(T x) { return x*x; }
#ifdef EgQrauETGh
template<typename T> void debpr(const T &);
template<typename T1, typename T2> void debpr(const pair<T1, T2> &);
template<typename T1, typename T2> void debpr(const vector<T1, T2> &);
template<typename T1, typename T2> void debpr(const set<T1, T2> &);
template<typename T1, typename T2> void debpr(const multiset<T1, T2> &);
template<typename T1, typename T2> void debpr(const map<T1, T2> &);
template<typename T, size_t n> void debpr(const array<T, n> &);
template<typename T> void prcont(T be, T en, const string &st, const string &fi, const string &mi) { debpr(st); bool ft=0; while (be!=en) { if (ft) debpr(mi); ft=1; debpr(*be); ++be; } debpr(fi); }
template<typename T> void debpr(const T &a) { cerr<<a; }
template<typename T1, typename T2> void debpr(const pair<T1, T2> &p) { debpr("("); debpr(p.first); debpr(", "); debpr(p.second); debpr(")"); }
template<typename T1, typename T2> void debpr(const vector<T1, T2> &a) { prcont(a.begin(), a.end(), "[", "]", ", "); }
template<typename T, size_t n> void debpr(const array<T, n> &a) { prcont(a.begin(), a.end(), "[", "]", ", "); }
template<typename T1, typename T2> void debpr(const set<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
template<typename T1, typename T2> void debpr(const multiset<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
template<typename T1, typename T2> void debpr(const map<T1, T2> &a) { prcont(a.begin(), a.end(), "{", "}", ", "); }
void debp() {}
template<typename T, typename... U> void debp(T x, U... y) { debpr(x); debpr(' '); debp(y...); }
template<typename... T> void debs(T... x) { debp(x...); debpr('\n'); }
bool asse() { return 1; }
template<typename T, typename... U> bool asse(T x, U... y) { return x && asse(y...); }
template<typename... T> void asss(string t, T... x) { if (!asse(x...)) { cerr<<t<<" ASSERTION FAILED!"<<endl; throw; }}
#define deb(...) debs("LINE "+to_string(__LINE__)+":\t", __VA_ARGS__)
#define ass(...) asss("LINE "+to_string(__LINE__)+":\t", __VA_ARGS__)
ostream& operator<<(ostream &o, __float128 f) { o<<(long double)f; return o; }
__float128 abs(__float128 x) { return x<0?-x:x; }
__float128 log(__float128 x) { return log((long double)(x)); }
__float128 sqrt(__float128 x) { return sqrt((long double)(x)); }
#else
#define deb(...) ;
#define ass(...) ;
#endif
const ld PI=acos(-1.);
ll Round(double x) { return x<0?x-.5:x+.5; }
int main()
{
#ifdef EgQrauETGh
    // FIN;
    ld tm=clock();
    cerr<<"====================================================="<<endl;
#else
    // freopen("list-powers.in", "r", stdin); freopen("list-powers.out", "w", stdout);
#endif
    void run(); run();
#ifdef EgQrauETGh
    cerr<<"====================================================="<<endl;
    cerr<<setprecision(3)<<fixed<<(clock()-tm)/CLOCKS_PER_SEC<<" sec" << endl;
    if (sizeof(ld)!=sizeof(double)) {
        cerr<<"WARNING:    ld is not double!"<<endl;
    }
#endif
    return 0;
}
#define pb push_back
#define X first
#define Y second

// g++ -Wall -Wno-sign-compare -Wno-unused-result -DEgQrauETGh -O3 -std=c++14 -o main main.cpp
// ulimit -s unlimited
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CI NN=30, M=10;
int nte, a[101*101][101], h[101*101][101];
// int d[NN][NN][NN];
set<AI3> s;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void inc(int i, int j, int d)
{
    s.erase({a[i][j], i, j});
    a[i][j]+=d;
    s.insert({a[i][j], i, j});
}
int go1(int n, int m, int k)
{
    s.clear();
    REP(i, n) REP(j, m) a[i][j]=0, s.insert({a[i][j], i, j});
    int rs=0;
    while (k)
    {
        --k;
        ass(s.size());
        AI3 p=*s.begin();
        s.erase(s.begin());
        rs+=p[0];
        int i=p[1], j=p[2];
        a[i][j]=-1;
        REP(z, 4)
        {
            int x=i+dx[z], y=j+dy[z];
            if (a[x][y]<0||x<0||y<0||x>=n||y>=m) continue;
            inc(x, y, 1);
        }
    }
    return rs;
}
int go2(int n, int m, int k)
{
    s.clear();
    int rs=(n-1)*m+(m-1)*n;
    REP(i, n) REP(j, m)
    {
        a[i][j]=0;
        REP(z, 4)
        {
            int x=i+dx[z], y=j+dy[z];
            if (x<0||y<0||x>=n||y>=m) continue;
            --a[i][j];
        }
        s.insert({a[i][j], i, j});
    }
    while (k<n*m)
    {
        ++k;
        ass(s.size());
        AI3 p=*s.begin();
        s.erase(s.begin());
        rs+=p[0];
        int i=p[1], j=p[2];
        a[i][j]=1;
        REP(z, 4)
        {
            int x=i+dx[z], y=j+dy[z];
            if (a[x][y]>0||x<0||y<0||x>=n||y>=m) continue;
            inc(x, y, 1);
        }
    }
    return rs;
}
int ca(int n, int m, int k)
{
    if (n<m) swap(n, m);
    ass(n<101*101);
    ass(m<101);
    return min(go1(n, m, k), go2(n, m, k));
    REP(i, n) REP(j, m) h[i][j]=0;
    REP(i, n)
    {
        int j=i%2;
        while (k&&j<m) h[i][j]=1,j+=2,--k;
    }
    VINT X {0, n-1}, Y {0, m-1};
    FORA(x, X) FORA(y, Y) if (k&&!h[x][y]) h[x][y]=1,--k;
    REP(i, n) if (k&&!h[i][0]) h[i][0]=1,--k;
    REP(i, n) if (k&&!h[i][m-1]) h[i][m-1]=1,--k;
    REP(j, m) if (k&&!h[0][j]) h[0][j]=1,--k;
    REP(j, m) if (k&&!h[n-1][j]) h[n-1][j]=1,--k;
    REP(i, n) REP(j, m) if (k&&!h[i][j]) h[i][j]=1,--k;
    ass(!k);
    int w=0;
    REP(i, n) REP(j, m) if (h[i][j])
    {
        if (i&&h[i-1][j]) ++w;
        if (j&&h[i][j-1]) ++w;
    }
    return w;
}
int ca1(int n, int m, int k)
{
    int c0=0, c3=0, c4=0;
    REP(i, n)
    {
        int f=(m+1-(i%2))/2;
        c0+=f;
        if (i==0||i==n-1) c3+=m-f;
        else
        {
            if (i%2) --f, ++c3;
            if (m>1&&(i%2)==(m%2)) --f, ++c3;
            c4+=f;
            ass(f>=0);
        }
    }
    ass(c0+c3+c4==n*m);
    if (k<=c0) return 0;
    k-=c0;
    if (k<=c3) return 3*k;
    k-=c3;
    ass(k<=c4);
    return 4*k;
}
void run()
{
    // SINF(d);
    // FOR(n, 1, M) FOR(m, 1, M)
    // {
    //     int k=n*m;
    //     if (k>M) continue;
    //     REP(ms, 1<<k)
    //     {
    //         int w=0, c=0;
    //         REP(i, n) REP(j, m) a[i][j]=bool(ms&(1<<(i*m+j)));
    //         REP(i, n) REP(j, m) if (a[i][j])
    //         {
    //             ++c;
    //             if (i&&a[i-1][j]) ++w;
    //             if (j&&a[i][j-1]) ++w;
    //         }
    //         d[n][m][c]=min(d[n][m][c], w);
    //     }
    //     REP(i, k+1) if (d[n][m][i]!=ca(n, m, i))
    //     {
    //         deb(n, m, i);
    //         deb(d[n][m][i], ca(n, m, i));
    //         ass(n<4||m<4);
    //         ass(0);
    //     }
    // }
    scanf("%d", &nte);
    REP(nt, nte)
    {
        printf("Case #%d: ", nt+1);
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        printf("%d\n", ca(n, m, k));
    }
}
