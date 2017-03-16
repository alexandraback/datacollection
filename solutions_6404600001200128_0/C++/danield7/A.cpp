#include<bits/stdtr1c++.h>
using namespace std;

int T, N, M[1005], total, MAX;

int main () {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> M[i];
    total = 0;
    MAX = 0;
    for (int i = 0; i < N - 1; ++i) {
      int temp = max(0, M[i] - M[i + 1]);
      MAX = max(MAX, temp);
      total += temp;
    }
    cout << total << " ";
    total = 0;
    for (int i = 0; i < N - 1; ++i) total += min(M[i], MAX);
    cout << total << endl;
  }
  return 0;
}
