#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int B, N;
VI M;

lint calc(lint t) {
  lint c = 0;
  REP (i, B) {
    c += t / M[i] + (t % M[i] == 0 ? 0 : 1);
  }
  return c;
}

int work() {
  scanf("%d%d", &B, &N);

  M.assign(B, 0);
  REP (i, B) {
    scanf("%d", &M[i]);
  }

  lint l = 0, r = 1e18, m;
  while (l < r) {
    if (calc(m = (l + r) / 2 + 1) < N) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  lint idx = calc(m = l) + 1;

  VI remain(B, 0);
  REP (i, B) {
    remain[i] = m % M[i] == 0 ? 0 : M[i] - m % M[i];
  }

  while (true) {
    int t = *min_element(ALL(remain));
    REP (i, B) {
      remain[i] -= t;
    }
    REP (i, B) {
      if (remain[i] == 0) {
        remain[i] = M[i];
        if (idx == N) {
          return i + 1;
        }
        ++idx;
      }
    }
  }

  assert(false);
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, work());
  }
  return 0;
}
