#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main() {
  int T; cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int N; cin >> N;
    vi v(N); for (int& x : v) cin >> x;
    int r1 = 0, M = 0;
    for (int i = 1; i < N; ++i) {
      r1 += max(0, v[i-1] - v[i]);
      M = max(M, v[i-1] - v[i]);
    }
    int r2 = 0;
    for (int i = 1; i < N; ++i) r2 += min(M, v[i-1]);
    cout << "Case #" << cas << ": " << r1 << ' ' << r2 << endl;
  }
}
