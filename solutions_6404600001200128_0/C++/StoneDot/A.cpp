#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; int m[10100];
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> m[i];
    }
    cout << "Case #" << t << ": ";
    int mustEat = 0;
    for (int i = 1; i < N; i++) {
      if (m[i] < m[i - 1]) {
        mustEat += m[i - 1] - m[i];
      }
    }
    cout << mustEat << " ";
    int maxRate = 0;
    for (int i = 1; i < N; i++) {
      if (m[i] < m[i - 1]) {
        maxRate = max(maxRate, m[i - 1] - m[i]);
      }
    }
    int eated = 0;
    for (int i = 0; i < N - 1; i++) {
      eated += min(maxRate, m[i]);
    }
    cout << eated << endl;
  }
  return 0;
}