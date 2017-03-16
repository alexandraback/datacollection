#include <iostream>
#include <thread>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

const int kThread = 32;
const int maxn = 3010;
// const int maxn = 10;

int n;
int x[maxn];
int y[maxn];
int f[maxn][maxn];

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
}

int64_t mul(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
  return x1 * y2 - x2 * y1;
}

int64_t mul(
    int64_t x1, int64_t y1, int64_t x2, int64_t y2, int64_t x3, int64_t y3) {
  return mul(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
}

void calc(int i, int j) {
  int l = 0, r = 0;
  for (int k = 0; k < n; k++) {
    auto s = mul(x[i], y[i], x[j], y[j], x[k], y[k]);
    if (s < 0) {
      l++;
    } else if (s > 0) {
      r++;
    }
  }
  f[i][j] = min(l, r);
}

void work() {
  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  std::list<thread> s;
  for (int i = 0; i < n; i++) {
    s.emplace_back([i]() {
      for (int j = 0; j < n; j++) {
        calc(i, j);
      }
    });
    if (s.size() > kThread) {
      s.front().join();
      s.pop_front();
    }
  }

  for (auto& i : s) {
    i.join();
  }

  for (int i = 0; i < n; i++) {

    int ans = n;
    for (int j = 0; j < n; j++) {
      if (i != j) {
        ans = min(ans, f[i][j]);
      }
    }

    cout << ans << endl;
  }
}

int main() {
  cin.sync_with_stdio(false);
  int cases;
  cin >> cases;
  for (int i = 1; i <= cases; i++) {
    input();
    cout << "Case #" << i << ":\n";
    work();
  }
}
