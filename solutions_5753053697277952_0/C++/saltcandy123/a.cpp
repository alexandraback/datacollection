#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
  int t, n, r, pos;
  int p[26];
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
    }
    r = accumulate(p, p + n, 0);
    cout << "Case #" << case_num << ":";
    while (true) {
      pos = max_element(p, p + n) - p;
      if (p[pos] == 0) {
        break;
      }
      --r;
      --p[pos];
      cout << ' '  << char('A' + pos);
      pos = max_element(p, p + n) - p;
      if (p[pos] * 2 > r) {
        --r;
        --p[pos];
        cout << char('A' + pos);
      }
    }
    cout << endl;
  }
  return 0;
}
