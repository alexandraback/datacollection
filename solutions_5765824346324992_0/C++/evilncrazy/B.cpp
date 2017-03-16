#include <cstdio>
#include <algorithm>
#include <queue>

typedef std::pair<int, int> ii;

int M[1002];

void tcase(int t) {
  int b, n; scanf("%d %d", &b, &n);
  n--;

  int cycle = 1;
  std::priority_queue<ii, std::vector<ii>, std::greater<ii> > pq;
  for (int i = 0; i < b; i++) {
    scanf("%d", &M[i]);
    cycle *= M[i];
    pq.push(std::make_pair(0, i));
  }

  int cycleLen = 0;
  for (int i = 0; i < b; i++) {
    cycleLen += cycle / M[i];
  }

  n %= cycleLen;
  for (int i = 0; i < n; i++) {
    ii next = pq.top();
    pq.pop();
    pq.push(std::make_pair(next.first + M[next.second], next.second));
  }

  printf("Case #%d: %d\n", t, pq.top().second + 1);
}

int main() {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; t++)
    tcase(t);
}
