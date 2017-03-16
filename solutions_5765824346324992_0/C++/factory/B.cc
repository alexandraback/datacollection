#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef int64_t i64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> ii;

inline int CalcLcm(int a, int b) {
  const int orig_a = a;
  const int orig_b = b;
  int c = 0;
  do {
    c = a % b;
    a = b;
    b = c;
  } while (c != 0);
  return orig_a / a * orig_b;
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int B = 0;
    int N = 0;
    cin >> B >> N;

    vi data;
    data.reserve(B);
    int lcm = 0;
    for (int i = 0; i < B; ++i) {
      int el = 0;
      cin >> el;
      data.push_back(el);
      if (lcm == 0) {
        lcm = el;
      } else {
        lcm = CalcLcm(lcm, el);
      }
    }

    int lcm_fill = 0;
    for (int i = 0; i < B; ++i) {
      lcm_fill += lcm / data[i];
    }
    if (N > lcm_fill) {
      N = N % lcm_fill;
    }

    int answer = 0;
    if (N == 0) {
      answer = B;
    } else {
      static array<i64, 10> accum;
      accum.fill(0);
      for (int i = 1; i <= N; ++i) {
        int min_index = 0;
        i64 min_val = accum[0];
        for (int j = 1; j < B; ++j) {
          if (accum[j] < min_val) {
            min_val = accum[j];
            min_index = j;
          }
        }
        accum[min_index] += data[min_index];
        if (i == N) {
          answer = min_index + 1;
        }
      }
    }

    cout << "Case #" << tt << ": " << answer << "\n";
  }
  
  return 0;
}
