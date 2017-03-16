#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define SQR(x) ((x) * (x))
using namespace std;
const int inf = 1 << 29;
const int maxn = 3002;
const int maxm = 102;
const int mod = 100007;

/*
struct Node {
  int v,w;
  int next;
}edge[maxn << 1];
int head[maxn << 1];
bool vis[maxn];
int m,n,idx;

void init() {
  memset(head,-1,sizeof(head));
  memset(vis, false, sizeof(vis));
  idx = 0;
  return;
}

void addedge(int u, int v, int w) {
  edge[idx].v = v;
  edge[idx].w = w;
  edge[idx].next = head[u];
  head[u] = idx++;

  edge[idx].v = u;
  edge[idx].w = w;
  edge[idx].next = head[v];
  head[v] = idx++;
  return;
}

bool flag[maxn];
int phi[maxn];
vector<int> prime;

void get_prime_phi() {
  memset(flag, false, false);
  prime.clear();

  phi[1] = 1;
  for (int i=2;i<maxn;i++) {
    if (!flag[i]) {
      printf("%d ",i);
      prime.push_back(i);
      phi[i] = i-1;
    }
    for (int j=0;j<prime.size() && i*prime[j]<maxn; j++) {
      flag[i * prime[j]] = true;
      if (i % prime[j]) {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      } else {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
    }
  }
  return;
}

long long extend_gcd(long long a,long long b,long long &x,long long &y) {
  if(a == 0 && b == 0) return -1;
  if(b == 0){x = 1; y = 0; return a;}
  long long d = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

long long mod_reverse(long long a, long long n) {
  long long x,y;
  long long d = extend_gcd(a, n, x, y);
  if(d == 1) return (x % n + n) % n;
  else return -1;
}

int c[maxn << 1];
int lowbit(int x) {
  return x & (-x);
}

void update(int x, int num) {
  while(x < maxn) {
    c[x] += num;
    x += lowbit(x);
  }
  return;
}

int getSum(int x) {
  int cnt = 0;
  while(x > 0) {
    cnt += c[x];
    x -= lowbit(x);
  }
  return cnt;
}

long long multi(long long m, long long n, long long k) {
  long long res = 0;
  while(n) {
    if (n & 1) {
      res += m;
      res %= k;
    }
    m = (m + m) % k;
    n >>= 1;
  }
  return res;
}

// m^n % k
long long quickpow(long long m, long long n, long long k) {
  long long res = 1LL;
  while (n) {
    if (n & 1) {
      res = multi(res, m, k);
    }
    m = multi(m, m, k);
    n >>= 1;
  }
  return res;
}
*/

struct PPP {
  int x,y;
}po[maxn], P[maxn], S[maxn];
int m, n, top;
int ans[maxn];
bool bj[maxn];
const double eee = 1e-6;

void read() {
  scanf("%d", &n);
  for (int i=0;i<n;i++) {
    scanf("%d%d", &po[i].x, &po[i].y);
  }
  return;
}

double Dis(const PPP& p1,const PPP& p2)
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)*1.0 );
}

double Cross(const PPP& p1,const PPP& p2,const PPP& p3,const PPP& p4)
{
    return (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
}

bool cmp(const PPP& p1,const PPP& p2)
{
    double C = Cross(P[0],p1,P[0],p2);
    return C ? C>0 : Dis(P[0],p1)<Dis(P[0],p2);
}

void Pole_PPP()
{
    int id;
    PPP pp = P[id=0];
    for(int i=1;i<m;i++)
        if(P[i].y < pp.y || P[i].y == pp.y && P[i].x < pp.x)
            pp = P[i] , id = i;
    P[id] = P[0] , P[0] = pp;
}

bool check(int idx)
{
    Pole_PPP();
    sort(P+1,P+m,cmp);
    S[0]=P[0],S[top=1]=P[1];
    for(int i=2;i<m;i++)
    {
        while(top && Cross(S[top-1],S[top],S[top],P[i]) < 0)
            --top;
        S[++top] = P[i];
    }
    for (int i=0;i<=top;i++) {
      if (S[i].x == po[idx].x && S[i].y == po[idx].y) return true;
    }
    return false;
}


void solve() {
  for (int i=0;i<n;i++) ans[i] = inf;
  for (int i=0;i<(1<<n);i++) {
    for (int j=0;j<n;j++) {
      int st = i | (1 << j);
      m = 0;
      for (int k=0;k<n;k++) {
        if (st & (1 << k)){
          P[m].x = po[k].x;
          P[m++].y = po[k].y;
        }
      }
      if (check(j)) {
        ans[j] = MIN(ans[j], n-m);
      }
    }
  }

  for (int i=0;i<n;i++) {
    printf("%d\n", ans[i]);
  }
  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  freopen("C-small-attempt0.in", "r", stdin);
  //freopen("A-large.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int cas;
  scanf("%d", &cas);
  for (int i=1;i<=cas;i++) {
    printf("Case #%d:\n",i);
    read();
    solve();
  }
  return 0;
}

