#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int main() {
  int n_cases;
  cin >> n_cases;

  for (int i_case = 0; i_case < n_cases; i_case++) {
    int n;
    cin >> n;

    int m[n];
    long long ans_1 = 0;
    int prev_m = 0;
    int worst_diff = 0;
    for (int i = 0; i < n; i++) {
      cin >> m[i];

      int prev_diff = prev_m - m[i];
      if (prev_diff > 0) {
        ans_1 += prev_diff;
      }
      prev_m = m[i];

      worst_diff = max(worst_diff, prev_diff);
    }

    long long ans_2 = 0;
    for (int i = 0; i < n - 1; i++) {
      ans_2 += min(m[i], worst_diff);
    }

    printf("Case #%d: %lld %lld\n", i_case + 1, ans_1, ans_2);
  }

  return 0;
}
