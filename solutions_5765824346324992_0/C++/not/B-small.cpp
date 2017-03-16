#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void solve() {
  long long b, n;
  cin >> b >> n;
  long long m[b];
  for (int i = 0; i < b; ++i) cin >> m[i];
  long long lcm = 1;
  for (int i = 0; i < b; ++i) {
    lcm = lcm / __gcd(lcm, m[i]) * m[i];
  }
  long long cnt = 0;
  for (int i = 0; i < b; ++i) cnt += lcm / m[i];
  n %= cnt;
  if (n == 0) n = cnt;
  priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> que;
  for (int i = 0; i < b; ++i) {
    que.push(make_pair(0, i));
  }
  for (int i = 0; i < n - 1; ++i) {
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
