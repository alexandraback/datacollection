#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> Vi;

int method1(const Vi& v) {
  int n = v.size();
  int res = 0;
  for (int i = 0; i + 1 < n; ++i) {
    res += max(0, v[i] - v[i + 1]);
  }
  return res;
}

int method2(const Vi& v) {
  int n = v.size();
  int s = 0;
  for (int i = 0; i + 1 < n; ++i) {
    s = max(s, v[i] - v[i + 1]);
  }
  int res = 0;
  for (int i = 0; i + 1 < n; ++i) {
    res += min(s, v[i]);
  }
  return res;
}

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    int n;
    cin >> n;
    Vi v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    cout << "Case #" << cas << ": " << method1(v) << " " << method2(v) << endl;
  }
}
