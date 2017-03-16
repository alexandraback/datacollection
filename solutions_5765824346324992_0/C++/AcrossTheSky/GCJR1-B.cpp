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
const int N = 10000;
int a[N];
int n, m;
LL check(LL x)
{
    LL res = 0;
    REP(i, 1, n) if (x % a[i] == 0) res += x / a[i];
    else res += x / a[i] + 1;
    return res;
}
int main()
{
    int T;
    cin >> T;
    REP(ca, 1, T) {
        read(n); read(m);
        REP(i, 1, n) read(a[i]);
        LL l = 0, r = 1e17, res;
        while (l <= r) {
            LL mid = (l + r) >> 1;
            if (check(mid) >= m) r = mid - 1;
            else l = mid + 1, res = mid;
        }
        int x = m - check(res);
        int ans = 0, tmp = 0;
        REP(i, 1, n) 
            if (res % a[i] == 0) {
                ++tmp;
                if (tmp == x) {
                    ans = i;
                    break;
                }
            }
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
