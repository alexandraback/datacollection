#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int b, n;
vector<int> barbers;

// positive if too high
// neg if too low
// zero if just right
int guess(ll time, int& ans) {
  ll min_total = 0, max_total = 0;
  vector<int> valid_barbers;
  for (int i = 0; i < barbers.size(); ++i) {
    max_total += (time / barbers[i]) + 1;
    if (time % barbers[i] == 0) valid_barbers.push_back(i + 1);
  }
  min_total = max_total - valid_barbers.size() + 1;

  if (min_total > n) return 1; // served too many
  if (max_total < n) return -1; // served too few

  ans = valid_barbers[n - min_total];
  return 0;
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cin >> b >> n;
    barbers.clear();
    barbers.resize(b);
    for (int i = 0; i < b; ++i) cin >> barbers[i];

    int ans;
    ll low = 0;
    ll high = 100000000000000; // max possible time
    while (high > low) {
      ll mid = (low + high) / 2;
      int result = guess(mid, ans);
      if (result > 0) {
        high = mid;
      } else if (result < 0) {
        low = mid;
      } else {
        break;
      }
    }
    cout << "Test #" << test << ": " << ans <<  endl;
  }
  return 0;
}