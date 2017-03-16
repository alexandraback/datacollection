#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cctype>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
const int inf = 0x3f3f3f3f;
const int maxn = 30;
struct node {
  int id, v;
  node(int id, int v): id(id), v(v) {}
  bool operator < (const node& rhs) const {
    return v < rhs.v;
  }
};
priority_queue<node> q;

int main() {
  freopen("/Users/wangchengrui/Desktop/A-large.in.txt", "r", stdin);
  freopen("/Users/wangchengrui/Desktop/A-large.out.txt", "w", stdout);
  int t, tt = 0;
  scanf("%d", &t);
  while (t--) {  
    int n, x;
    scanf("%d", &n);
    q = priority_queue<node>();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x);
      q.push(node(i, x));
    }
    printf("Case #%d:", ++tt);
    while (q.size() > 2) {
      node k = q.top();
      q.pop();
      printf(" %c", k.id + 'A');
      if (--k.v > 0) {
        q.push(k);
      }
    }
    int id1 = q.top().id, v1 = q.top().v;
    q.pop();
    int id2 = q.top().id, v2 = q.top().v;
    int dt = v1 - v2;
    while (dt > 2) {
      printf(" %c", id1 + 'A');
      dt -= 2;
    }
    if (dt & 1) {
      printf(" %c", id1 + 'A');
    }
    while (v2--) {
      printf(" %c%c", id1 + 'A', id2 + 'A');
    }
    puts("");
  }
  return 0;
}
