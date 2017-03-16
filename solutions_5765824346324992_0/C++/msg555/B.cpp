#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    long long N, P;
    cin >> N >> P;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    long long lo = 0;
    long long hi = (long long)A[0] * P;
    while (lo < hi) {
      long long md = (lo + hi) / 2;
      long long cnt = 0;
      for (int i = 0; i < N; i++) {
        cnt += md / A[i] + 1;
      }
      if (cnt < P) {
        lo = md + 1;
      } else {
        hi = md;
      }
    }
    for (int i = 0; i < N; i++) {
      P -= lo / A[i] + 1;
    }

    cout << "Case #" << t << ": ";
    for (int i = N - 1; i >= 0; i--) {
      if (lo % A[i] == 0) {
        if (P++ == 0) {
          cout << i + 1 << '\n';
          break;
        }
      }
    }
  }
  return 0;
}
