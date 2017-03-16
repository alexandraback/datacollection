#include <iostream>
#include <cassert>
#include <cstdio>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define RVC(i, c) fot (int i = 0; i < (c).size(); ++i)
#define RSQ(i, a, b) for (int i = (a); 1LL * i * i <= (LL)(b); ++i)
#define RED(k, u) for (int k = head[(u)]; k; k = edge[k].next)
#define REE(k, u, h) for (int k = h[(u)]; k; k = edge[k].next)
#define lowbit(x) ((x) & (-(x)))
#define CL(x, v) memset(x, v, sizeof x)
#define ITER(ta, tb) ta<tb>::iterator
#define RCN(k, ta, tb, a) for (ITER(ta, tb) k = a.begin(); k != a.end(); ++k)
#define PLM(x, a, c) x = ((x + (a) % (c)) % (c))
#define MLM(x, a, c) x = (((x - (a) % (c)) % (c) + (c)) % (c))
#define MUM(x, a, c) x = (x * ((a) % (c))) % (c)
#define MP make_pair
#define PB push_back
#define FR first
#define SC second
#define SZ size()
#define rank rankk
#define next nextt
#define link linkk
#define index indexx
#define abs(x) ((x) > 0 ? (x) : (-(x)))
#define FILEIN(s)\
	FILENAME = s;\
	freopen((FILENAME + ".in").c_str(), "r", stdin);
#define FILEOUT(s)\
	FILENAME = s;\
	freopen((FILENAME + ".out").c_str(), "w", stdout);
#define FILEIO(s)\
	FILENAME = s;\
	freopen((FILENAME + ".in").c_str(), "r", stdin);\
	freopen((FILENAME + ".out").c_str(), "w", stdout);

using namespace std;
string FILENAME;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, int> PLI;
typedef pair<LL, int> PLL;
typedef pair<int, LL> PIL;
typedef pair<int, string> PIS;
typedef pair<string, int> PSI;
typedef pair<double, int> PDI;
typedef pair<int, double> PID;
typedef pair<double, double> PDD;


template<class T> inline
void getmin(T &a, const T &b)
{
	if (b < a) a = b;
}

template<class T> inline
void getmax(T &a, const T &b)
{
	if (b > a) a = b;
}

template<class T> inline
void read(T &a)
{
    char c;
    while (isspace(c = getchar()));
    bool flag = 0;
    if (c == '-') flag = 1, a = 0;
    else a = c - 48;
    while (isdigit(c = getchar())) a = a * 10 + c - 48;
    if (flag) a = -a;
}
#define OPTIM __attribute__((optimize("-O2")))
/*======================= TEMPLATE =======================*/
const int N = 20;
PII S[N];
PII a[N];
PII base;
LL area(PII c, PII a, PII b)
{
    return 1LL * (a.FR - c.FR) * (b.SC - c.SC) - 1LL * (a.SC - c.SC) *(b.FR - c.FR);
}
LL area(PII a, PII b)
{
    return 1LL * a.FR * b.SC - 1LL * a.SC * b.FR;
}
int n;
LL dis(PII a, PII b)
{
    int x = b.FR - a.FR, y= b.SC - a.SC;
    return 1LL * x * x + 1LL * y * y;
}
bool cmp(PII a, PII b)
{
    if (b == base) return false;
    else if (a == base) return true;
    LL x = area(base, b, a);
    if (x == 0) return dis(base,a) > dis(base, b);
    else return x > 0;
}
PII b[N], c[N];
bool check(int sta, int x)
{
    if (!(sta & (1 << (x - 1)))) return false;
    base.FR = 1e7;
    int m = 0;
    REP(i, 1, n) if (sta & (1 << (i - 1))) b[++m] = a[i];
    REP(i, 1, m) getmin(base, b[i]);
    if (m <= 3) return true;
    sort(b + 1, b + m + 1, cmp);
    int tot = 2;
    c[1] = b[1];c[2] = b[2];
    REP(i, 3, m) if (area(base, b[i - 1], b[i]) != 0) c[++tot] = b[i];
    int h = 2;
    S[1] = c[1]; S[2] = c[2];
    REP(i, 3, tot) {
        while (h >= 2 && area(S[h - 1], S[h], c[i]) > 0) --h;
        S[++h] = c[i];
    }
    REP(i, 1, h) if (area(S[i], a[x],S[i % h + 1]) == 0) {
        return true;}
    return false;
}
        
int main()
{
    int T;
    cin >> T;
    REP(ca, 1, T) {
        read(n);
        REP(i, 1, n) {
            read(a[i].FR);read(a[i].SC);
        }
        printf("Case #%d:\n", ca);
        REP(i, 1, n) {
            int ans = n;
            REP(j, 0, (1 << n) - 1) if (check(j, i)) getmin(ans, n - __builtin_popcount(j));
            printf("%d\n", ans);
        }
    }
    return 0;
}

