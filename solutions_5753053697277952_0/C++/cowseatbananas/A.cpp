#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, N, P[26], A[26];

void ptwo(int i, int j) {
  --P[i]; --P[j];
  printf(" %c%c", i + 'A', j + 'A');

  int sum = 0, mx = 0;
  FOR (i, N) sum += P[i], mx = max(mx, P[i]);
  if (mx * 2 > sum) assert(false);
}

void pone(int i) {
  --P[i];
  printf(" %c", i + 'A');
  int sum = 0, mx = 0;
  FOR (i, N) sum += P[i], mx = max(mx, P[i]);
  if (mx * 2 > sum) assert(false);
}

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%d", &N);

    typedef pair<int, int> ii;
    priority_queue<ii> pq;

    printf("Case #%d:", tc);

    int sum = 0;
    FOR (i, N) {
      scanf("%d", &P[i]);
      sum += P[i];
      pq.emplace(P[i], i);
    }

    if (N == 2) {
      while (sum) {
        ptwo(0, 1);
        sum -= 2;
      }
    } else {
      while (sum > 4) {
        auto x = pq.top().second; pq.pop();
        pone(x);
        pq.emplace(P[x], x);
        --sum;
      }

      if (sum == 1) {
        auto x = pq.top().second; pq.pop();
        pone(x);
      } else if (sum == 2) {
        if (pq.size() == 1) {
          auto x = pq.top().second; pq.pop();
          ptwo(x, x);
        } else {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          ptwo(x, y);
        }
      } else if (sum == 3) {
        if (pq.size() == 1) {
          auto x = pq.top().second; pq.pop();
          pone(x);
          ptwo(x, x);
        } else if (pq.size() == 2) {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          pone(x);
          ptwo(x, y);
        } else if (pq.size() == 3) {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          auto z = pq.top().second; pq.pop();
          pone(x);
          ptwo(y, z);
        }
      } else if (sum == 4) {
        if (pq.size() == 1) {
          auto x = pq.top().second; pq.pop();
          ptwo(x, x);
          ptwo(x, x);
        } else if (pq.size() == 2) {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          assert(P[x] != 3);
          ptwo(x, y);
          ptwo(x, y);
        } else if (pq.size() == 3) {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          auto z = pq.top().second; pq.pop();
          ptwo(x, x);
          ptwo(y, z);
        } else if (pq.size() == 4) {
          auto x = pq.top().second; pq.pop();
          auto y = pq.top().second; pq.pop();
          auto z = pq.top().second; pq.pop();
          auto zz = pq.top().second; pq.pop();
          ptwo(x, y);
          ptwo(z, zz);
        }
      }
    }

    printf("\n");
  }
  return 0;
}
