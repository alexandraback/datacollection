#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

void solve() {
  int n;
  cin >> n;
  if (n == 2) {
    int p1, p2;
    cin >> p1 >> p2;
    for (int i = 0; i < p1; ++i) {
      cout << " AB";
    }
    return;
  }
  priority_queue<pair<int, int>> que;
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    que.emplace(p, i);
  }
  vector<char> res;
  while (!que.empty()) {
    auto now = que.top();
    que.pop();
    res.emplace_back(now.second + 'A');
    --now.first;
    if (now.first) que.emplace(now);
  }
  for (int i = 0; i < (int)res.size() - 1; ++i) {
    cout << " " << res[i];
  }
  cout << res.back();
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ":";
    solve();
    cout << endl;
  }
}
