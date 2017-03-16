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

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  int T = 0;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    int N = 0;
    cin >> N;

    vi data;
    data.reserve(N);
    for (int i = 0; i < N; ++i) {
      int mi = 0;
      cin >> mi;
      data.push_back(mi);
    }

    int answer1 = 0;
    int max_drop = 0;
    for (int i = 1; i < N; ++i) {
      if (data[i] < data[i - 1]) {
        int drop = (data[i - 1] - data[i]);
        answer1 += drop;

        max_drop = max(max_drop, drop);
      }
    }
    int answer2 = 0;
    if (max_drop > 0) {
      for (int i = 0; i < N - 1; ++i) {
        answer2 += min(data[i], max_drop);
      }
    }

    cout << "Case #" << tt << ": " << answer1 << " " << answer2 << "\n";
  }
  
  return 0;
}
