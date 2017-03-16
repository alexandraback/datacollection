#include <iostream>
#include <queue>

using namespace std;

void solve() {
  long long b, n;
  cin >> b >> n;
  long long m[b];
  for (int i = 0; i < b; ++i) cin >> m[i];
  if (n <= b) {
    cout << n << endl;
    return;
  }
  long long u = 1e18, l = 0;
  while (l + 1 < u) {
    long long mid = (u + l) / 2;
    long long c = 0;
    for (int i = 0; i < b; ++i) {
      c += mid / m[i] + 1;
      if (c >= n) break;
    }
    if (c >= n) u = mid;
    else l = mid;
  }
  long long c = 0;
  for (long long i = 0; i < b; ++i) {
    c += l / m[i] + 1;
  }
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> que;
  for (int i = 0; i < b; ++i) {
    que.push(make_pair(l / m[i] * m[i] + m[i], i));
  }
  for (int i = c; i < n - 1; ++i) {
    auto now = que.top();
    que.pop();
    que.push(make_pair(now.first + m[now.second], now.second));
  }
  cout << que.top().second + 1 << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
