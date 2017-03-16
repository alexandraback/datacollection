#include<bits/stdtr1c++.h>
using namespace std;

typedef long long ll;
ll T, B, N, M[1005];

int main () {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    cin >> B >> N;
    for (int i = 0; i < B; ++i) cin >> M[i];
    ll low = 0, hi = 1000000000000000LL;
    while (hi - low > 1) {
      ll count = 0, mid = (low + hi) / 2;
      for (int i = 0; i < B; ++i) count += mid / M[i] + 1;
      if (count >= N) hi = mid;
      else low = mid;
    }
    if (N <= B) cout << N << endl;
    else {
      ll count = 0;
      for (int i = 0; i < B; ++i) count += low / M[i] + 1;
      count = N - count;
      if (count <= 0 || count > B) cout << "------->" << count << "<-------";
      vector<pair<int, int> > v(B);
      for (int i = 0; i < B; ++i) {
        v[i].second = i + 1;
        v[i].first = (low / M[i] + 1) * M[i] - low;
      }
      sort(v.begin(), v.end());
      cout << v[count - 1].second << endl;
    }
  }
  return 0;
}
