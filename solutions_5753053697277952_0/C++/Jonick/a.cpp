#include <bits/stdc++.h>

using namespace std;

void solveTest() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  while (true) {
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] > a[idx])
	idx = i;
    }
    if (a[idx] == 0)
      break;
    if (sum % 2 == 1) {
      sum = 0;
      cout << (char)('A' + idx) << " ";
      a[idx]--;
      continue;
    }
    int idx2 = -1;
    for (int i = 0; i < n; i++) {
      if (i != idx && a[i] > 0) {
	idx2 = i;
      }
    }
    assert(idx2 >= 0);
    cout << (char)('A' + idx) << (char)('A' + idx2) << " ";
    a[idx]--;
    a[idx2]--;
  }
  cout << "\n";
}

int main() {
  int tn;
  cin >> tn;
  for (int tc = 0; tc < tn; tc++) {
    cout << "Case #" << (tc+1) << ": ";
    solveTest();
  }
  return 0;
}
