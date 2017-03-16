#include <iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

int check(int x, int n) {
  return (x >> n) & 1;
}

int count_bit(int n) {
  int count = 0;
  while (n > 0) {
    if (n & 1) count++;
    n >>= 1;
  }
  return count;
}

int solve() {
  int R;
  int C;
  int N;
  cin >> R >> C >> N;
  int min_ = INT_MAX;
  for (int i = 0; i < 1 << (R * C); i++) {
    if (count_bit(i) != N) {
      continue;
    }
    int count = 0;
    for (int y = 0; y < R - 1; y++) {
      for (int x = 0; x < C; x++) {
        if (check(i, y * C + x) && check(i, (y + 1) * C + x)) {
          count++;
        }
      }
    }
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C - 1; x++) {
        if (check(i, y * C + x) && check(i, y * C + x + 1)) {
          count++;
        }
      }
    }
    min_ = min(min_, count);
  }
  return min_;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    std::cout << "Case #" << i + 1 << ": " << solve() << std::endl;
  }
  return 0;
}
