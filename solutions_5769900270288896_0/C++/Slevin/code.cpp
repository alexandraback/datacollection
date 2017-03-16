#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

int ri() {
  static int res;
  scanf("%d", &res);
  return res;
}

template <typename T>
int numbits(T n) {
  return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
  timer() : t_(clock()) {}
  void restart() { t_ = clock(); }
  float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
  clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  timer t;
#endif
  run();
#ifdef LOCAL_HOST
  //printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
  return 0;
}

int arr[16][16];

void run() {

  int nn; cin >> nn;
  for (int cs = 0; cs < nn; ++cs) {
    int r, c, n;
    cin >> r >> c >> n;
    int res = 1000000;

    for (int i = 0 ; i < (1 << r * c); ++i) {
      if (numbits(i) != n) {
        continue;
      }
      memset(arr, 0, sizeof(arr));
      for (int j = 0; j < r * c; ++j) {
        if ((1 << j) & i) {
          arr[j / c][j % c] = 1;
        }
      }
      int h = 0;
      for (int rr = 0; rr < r; ++rr) {
        for (int cc = 0; cc < c; ++cc) {
          if (arr[rr][cc]) {
            if (rr && arr[rr-1][cc]) {
              ++h;
            }
            if (cc && arr[rr][cc-1]) {
              ++h;
            }
          }
        }
      }
      res = min(res, h);
    }


    cout << "Case #" << cs + 1 << ": " << res << endl;
  }
}
