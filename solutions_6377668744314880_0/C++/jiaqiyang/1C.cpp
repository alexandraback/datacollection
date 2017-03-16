#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define x first
#define y second

typedef std::pair<int, int> point;

const int N = 3000 + 10;

int tcase, n;
int mx[N];

point a[N];

inline double slope(const point &a, const point &b) {
  return (double)(b.y - a.y) / (b.x - a.x);
}

void Convex(std::vector<point> &pool, int state) {
  std::vector<point> inf, sup;
  std::sort(pool.begin(), pool.end());
  inf.push_back(pool[0]);
  sup.push_back(pool[0]);
  for (int i = 1; i < pool.size(); ++i) {
    while (inf.size() > 1 && slope(inf[inf.size() - 2], inf.back()) > slope(inf[inf.size() - 2], pool[i])) inf.pop_back();
    while (sup.size() > 1 && slope(sup[sup.size() - 2], sup.back()) < slope(sup[sup.size() - 2], pool[i])) sup.pop_back();
    inf.push_back(pool[i]);
    sup.push_back(pool[i]);
  }
  for (int i = 0; i < sup.size(); ++i)
    for (int j = 1; j <= n; ++j)
      if (a[j] == sup[i]) mx[j] = std::min(mx[j], __builtin_popcount(state));
  for (int i = 0; i < inf.size(); ++i)
    for (int j = 1; j <= n; ++j)
      if (a[j] == inf[i]) mx[j] = std::min(mx[j], __builtin_popcount(state));
}

void DFS(int dep, int state) {
  if (dep > n) {
    static std::vector<point> pool;
    pool.clear();
    for (int i = 1; i <= n; ++i) 
      if (!(state >> i & 1)) pool.push_back(a[i]);
    Convex(pool, state);
    return;
  }
  DFS(dep + 1, state);
  DFS(dep + 1, state | (1 << dep));
}

int main() {
  scanf("%d", &tcase);
  for (int tid = 1; tid <= tcase; ++tid) {
    scanf("%d", &n);
    memset(mx, 0x3f, sizeof mx);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
    DFS(1, 0);
    printf("Case #%d:\n", tid);
    for (int i = 1; i <= n; ++i) printf("%d\n", mx[i]);
  }
  return 0;
}
