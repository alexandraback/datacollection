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
using namespace std;
const int inf = 1 << 29;
const int maxn = 1000002;
const int maxm = 102;
const int mod = 100007;

void in(int &x) {
  char ch=getchar();
  bool flag=false;
  while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if (ch=='-') {
    flag=true;
    ch=getchar();
  }
  x=0;
  while (ch>='0'&&ch<='9') {
    x=x*10+ch-'0';
    ch=getchar();
  }
  if (flag) x=-x;
}

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

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
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

int dp[20][20][20];
int m,n,p;

bool grid[20][20];

int fuck(int st) {
  int cnt = 0;
  while(st) {
    if (st & 1) cnt++;
    st >>= 1;
  }
  return cnt;
}

int move[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

int check(int st, int x, int y) {
  memset(grid, false, sizeof(grid));
  for (int i=0;i<x;i++) {
    for (int j=0;j<y;j++) {
      if (st & (1 << ((y*i)+j))) grid[i][j] = true;
    }
  }
  int cnt = 0;
  for (int i=0;i<x;i++) {
    for (int j=0;j<y;j++) {
      if (grid[i][j] == false) continue;
      for (int k=0;k<4;k++) {
        int tx = i + move[k][0];
        int ty = j + move[k][1];
        if (tx >= 0 && tx < x && ty >= 0 && ty < y && grid[tx][ty]) cnt++;
      }
    }
  }
  return cnt / 2;
}

int calc(int i, int j, int k) {
  int ans = inf;
  for (int st=0;st<1<<(i*j);st++) {
    if (fuck(st) != k) continue;
    ans = min(ans, check(st, i, j));
  }
  return ans;
}

void init() {
  memset(dp, -1, sizeof(dp));
  for (int i=1;i<=16;i++) {
    for (int j=i;j<=16;j++) {
      if (i*j > 16) continue;
      for (int k=0;k<=i*j;k++) {
        dp[i][j][k] = calc(i,j,k);
      }
    }
  }
  return;
}

void read() {
  return;
}

void solve() {
  scanf("%d%d%d", &m,&n,&p);
  printf("%d\n", dp[min(m,n)][max(m,n)][p]);
  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("B-small-attempt0.in", "r", stdin);
  //freopen("C-large.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d", &cas);
  init();
  for (int i=1;i<=cas;i++) {
    printf("Case #%d: ",i);
    //read();
    solve();
  }
  return 0;
}

