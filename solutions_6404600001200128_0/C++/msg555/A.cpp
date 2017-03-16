#include <iostream>
#include <vector>

using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    long long res1 = 0;
    int res2 = 0;
    for (int i = 1; i < N; i++) {
      res1 += max(0, A[i - 1] - A[i]);
      res2 = max(res2, A[i - 1] - A[i]);
    }

    long long res3 = 0;
    for (int i = 0; i + 1 < N; i++) {
      res3 += min(A[i], res2);
    }

    cout << "Case #" << t << ": " << res1 << ' ' <<  res3 << '\n';
  }
  return 0;
}
