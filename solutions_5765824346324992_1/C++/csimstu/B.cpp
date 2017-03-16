#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int M[1111];
ll B, N;

ll ceil(ll a, ll b) {
  if (a % b == 0) return a / b;
  return a / b + 1;
}

ll count(ll T) {
  ll cnt = 0;
  for (int i = 0; i < B; i++)
    cnt += ceil(T, M[i]);
  return cnt;
}

int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cin >> B >> N;
    for (int i = 0; i < B; i++)
      cin >> M[i];

    ll lb = 0, rb = 100000000000000000LL;
    while (lb < rb - 1) {
      ll mid = (lb + rb) / 2;
      if (count(mid) >= N)
        rb = mid;
      else
        lb = mid;
    }
    vector<pair<ll, int>> arr;
    for (int i = 0; i < B; i++) {
      if (rb % M[i] == 0)
        arr.push_back(make_pair(rb - M[i], i));
      else
        arr.push_back(make_pair(rb / M[i] * M[i], i));
    }
    sort(arr.begin(), arr.end());
    int rank = B - 1 - (count(rb) - N);
    cout << "Case #" << tc << ": " << arr[rank].second + 1 << endl;
  }
}
