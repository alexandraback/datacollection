#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <unordered_map>

using namespace std;

namespace MF {
  #define MAXN 201111
  #define MAXM 800010
  #define wint int
  const wint wEPS = 0;
  const wint wINF = 0x3F3F3F3F;//1001001001001001001LL;
  int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
  wint capa[MAXM], tof;
  int lev[MAXN], see[MAXN], que[MAXN], *qb, *qe;
  void init(int _n) {
    n = _n; m = 0; memset(ptr, ~0, n << 2);
  }
  void ae(int u, int v, wint w0, wint w1 = 0) {
    next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w0; ++m;
    next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = w1; ++m;
  }
  wint augment(int src, int ink, wint flo) {
    if (src == ink) return flo;
    wint f;
    for (int &i = see[src]; ~i; i = next[i]) if (capa[i] > wEPS && lev[src] < lev[zu[i]]) {
      if ((f = augment(zu[i], ink, min(flo, capa[i]))) > wEPS) {
        capa[i] -= f; capa[i ^ 1] += f; return f;
      }
    }
    return 0;
  }
  bool dinic(int src, int ink, wint flo = wINF) {
    wint f;
    int i, u, v;
    for (tof = 0; tof + wEPS < flo; ) {
      qb = qe = que;
      memset(lev, ~0, n << 2);
      for (lev[*qe++ = src] = 0, see[src] = ptr[src]; qb != qe; ) {
        for (i = ptr[u = *qb++]; ~i; i = next[i]) if (capa[i] > wEPS && !~lev[v = zu[i]]) {
          lev[*qe++ = v] = lev[u] + 1; see[v] = ptr[v];
          if (v == ink) goto au;
        }
      }
      return 0;
    au: for (; (f = augment(src, ink, flo - tof)) > wEPS; tof += f);
    }
    return 1;
  }
}
 
// Constants
const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0);//3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; //4 direction
//const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1}; //8 direction
//const int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1}; //Knight direction
//const int dx[] = {0, 1, 1, 0, -1, -1}, dy[] = {1, 1, 0, -1, -1, 0}; //Hexagonal direction(col x row y)
 
// Definitions
#define PB push_back
#define MP make_pair
#define SZ size()
 
#define FOR(i, s, e) for (int i = (s); i <= (int)(e); ++i)
#define FORD(i, s, e) for (int i = (s);i >= (int)(e); --i)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPD(i, n) for (int i = (n) - 1; i >= 0; --i)
#define FIT(it, x) for (typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define FITD(it, x) for (typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)
 
#define LET(a, b) typeof(b) a(b)
#define ALL(x) (x).begin(), (x).end()
#define CLR(x) memset((x), 0, sizeof(x))
#define SET(a, b) memset((a), b, sizeof(a))
#define EXIST(a, b) (find(all(a), b)!=a.end())
#define SORT(x) sort(ALL(x))
#define GSORT(x) sort(ALL(x), greater<typeof((x).begin())>())
#define gsort(a, b) sort(a, b, greater<typeof(*a)>())
#define OUT(x) cerr << #x << ":" << x << '@' << endl
#define PRV(v) REP(vi, v.SZ) cout << v[vi] << ' '; cout << endl
 
// Types
typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set<int> SI;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef map<string, int> MSI;
typedef map<int, int> MII;
typedef map<LL, int> MLLI;
typedef priority_queue<int> pq;
typedef priority_queue<int, vector<int>, greater<int> > pqg;
 
//Functions
inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ SS ss; ss << x; int r; ss >> r; return r; }
template<class T> inline int todouble(const T& x){ SS ss; ss << x; double r; ss >> r; return r; }
template<class T> inline string tostr(const T& x) { SS ss; ss << x; return ss.str(); }
inline string tolower(string s){ REP(i, s.SZ) s[i] = tolower(s[i]); return s; }
inline string toupper(string s){ REP(i, s.SZ) s[i] = toupper(s[i]); return s; }
 
template<class T> vector<T> split(string s, char c = ' ') { SS ss(s); vector<T> res; T t; while (ss >> t) { res.PB(t); if(ss.peek() == c) ss.ignore(); } return res; }
template<class T> vector<T> stov(string s) { vector<T> vi; SS ss(s); T v; while (ss >> v) vi.PB(v); return vi; }
template<class T> string vtos(const vector<T>& vi) { SS ss; REP(i, vi.SZ) { if (i > 0) ss << ' '; ss << vi[i]; } return ss.str(); }
 
// Maths
template<class T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> inline T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline vector<pair<T, int> > factorize(T n) { vector<pair<T, int> > R; for (T i = 2; n > 1; ) { if (n % i == 0) {
int C = 0; while (n % i == 0) C++, n /= i; R.PB(MP(i, C)); } i++; if (i > n / i) i = n; } if (n > 1) R.PB(MP(n, 1)); return R; }
template<class T> inline bool isprime(T n) { if (n < 2) return false; for (T i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
template<class T> inline T phi(T n) { vector<pair<T, int> > R = factorize(n); T r = n; REP(i, R.SZ) r = r / R[i].first * (R[i].first - 1); return r; }

int r, c, n;

int id_grid(int i, int j) {
  return i * c + j + 1;
}

int id_wall(int i, int j, int d) {
  int id = r * c + 1 + (c + c + 1) * i + j;
  if (d == 0) return id;
  if (d == 1) return id + c;
  if (d == 2) return id + c + 1;
  return id + c + c + 1;
}

int main() {
  int t;
  cin>>t;
  REP(ii, t) {
    cin>>r>>c>>n;
    int S = 0;
    int T = r * c + (2 * r * c + r + c) + 1;
    int NS = T + 1;
    MF::init(NS + 1);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        MF::ae(S, id_grid(i, j), 4);
        MF::ae(id_grid(i, j), id_wall(i, j, 0), 1);
        MF::ae(id_grid(i, j), id_wall(i, j, 1), 1);
        MF::ae(id_grid(i, j), id_wall(i, j, 2), 1);
        MF::ae(id_grid(i, j), id_wall(i, j, 3), 1);        
      }
    }
    for (int i = r * c + 1; i < T; ++i) MF::ae(i, T, 1);
    MF::ae(NS, S, 4 * n);
    MF::dinic(NS, T);
    cout<<"Case #"<<ii+1<<": "<<(4 * n - MF::tof)<<endl;
  }    
  return 0;
}