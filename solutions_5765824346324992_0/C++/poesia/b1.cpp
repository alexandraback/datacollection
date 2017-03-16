#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

int simulate(vector<int>& m, int x) {
  set<pair<int, int> > available;

  for (int i = 0; i < m.size(); i++)
    available.insert(make_pair(0, i));

  int last = -1;

  for (int i = 0; i <= x; i++) {
    pair<int, int> next = *available.begin();
    available.erase(available.begin());
    last = next.second;
    available.insert(make_pair(next.first + m[next.second], next.second));
  }

  return last;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    int b, n;
    cin >> b >> n;

    vector<int> m(b);

    int l = 1;

    for (int i = 0; i < b; i++) {
      cin >> m[i];
      l = lcm(l, m[i]);
    }

    int k = 0;

    for (int i = 0; i < b; i++) {
      k += l / m[i];
    }

    --n;
    n %= k;

    cout << "Case #" << t << ": " << (simulate(m, n) + 1) << '\n';
  }

  return 0;
}
