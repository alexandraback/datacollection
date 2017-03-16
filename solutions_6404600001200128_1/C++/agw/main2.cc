#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, N, m[1111];

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    int c1 = 0, c2 = 0;

    std::cin >> N;

    for (int i = 0; i < N; i ++) {
      std::cin >> m[i];

      if (i)
        c1 += std::max(m[i - 1] - m[i], 0);
    }

    int l = -1, u = 11111;

    while (u - l > 1) {
      int r = (l + u) / 2;

      int c = m[0];

      bool valid = true;

      for (int i = 1; i < N; i ++) {
        if (c - r <= m[i]) {
          c = std::max(c - r, m[i]);
        }
        else {
          valid = false;

          break;
        }
      }

      if (valid) {
        u = r;
      }
      else {
        l = r;
      }
    }

    for (int i = 0; i < N - 1; i ++)
      c2 += std::min(u, m[i]);

    std::cout << "Case #" << t << ": " << c1 << ' ' << c2 << std::endl;
  }
  
  return 0;
}
