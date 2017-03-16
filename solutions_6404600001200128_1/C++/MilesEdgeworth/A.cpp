#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    int vals[N];
    for (int i = 0; i < N; ++i) {
      cin >> vals[i];
    }

    int ans0 = 0;
    for (int i = 1; i < N; ++i) {
      int diff = vals[i-1] - vals[i];
      if (diff > 0) ans0 += diff;
    }

    int m = 1000000000;
    for (int j = 0; j < 100002; ++j) {
      int ans = 0;
      bool valid = true;
      for (int i = 1; i < N; ++i) {
        int eaten = min(j, vals[i - 1]);
        if (vals[i - 1] - eaten > vals[i]) {
          valid = false;
          break;
        }
        ans += eaten;
      }
      if (valid) {
      m = min(ans, m);}
    }

    cout << "Case #" << t << ": " << ans0 << " " << m << endl;
  }
}
