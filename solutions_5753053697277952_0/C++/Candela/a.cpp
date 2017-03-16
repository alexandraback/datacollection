#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define N 10010
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i <=n; i++)

int T, n, a[N];
priority_queue<pair<int, int> > Q;

void solve(int n) {
  while (!Q.empty()) Q.pop();
  rep(i, n) {
    scanf("%d", &a[i]);
    Q.push(make_pair(a[i], i));
  }
  while (Q.size() > 2) {
    pair<int, int> tmp = Q.top();
    Q.pop();
    putchar(tmp.second + 'A');
    putchar(' ');
    if (--tmp.first) {
      Q.push(tmp);
    }
  }
  pair<int, int> s1, s2;
  s1 = Q.top();
  Q.pop();
  s2 = Q.top();
  Q.pop();
  if (s1.first < s2.first) swap(s1, s2);
  while (s1.first > s2.first) {
    --s1.first;
    putchar(s1.second + 'A');
    if (s1.first == 0) putchar('\n'); else putchar(' ');
  }
  while (s1.first) {
    putchar(s1.second + 'A');
    putchar(s2.second + 'A');
	--s1.first; --s2.first;
    if (s1.first == 0) putchar('\n'); else putchar(' ');
  }
}

int main() {
  scanf("%d", &T);
  kep(_, T) {
    scanf("%d", &n);
    printf("Case #%d: ", _);
    solve(n);
  }
}
