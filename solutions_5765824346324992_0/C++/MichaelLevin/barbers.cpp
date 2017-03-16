#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "B"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

int SolveSlow(int b, int n, const vi& m) {
  int current_client = 1;
  set<pii> barber_free;
  for (int i = 0; i < b; ++i) {
    barber_free.insert(MP(0, i));
  }
  int result = -1;
  while (current_client <= n) {
    pii barber = *barber_free.begin();
    barber_free.erase(barber_free.begin());
    int time = barber.first;
    int index = barber.second;
    if (current_client == n) {
      result = index + 1;
      break;
    }
    barber_free.insert(MP(time + m[index], index));
    ++current_client;
  }
  return result;
}

ll ComputeEnteredBefore(int b, const vi& m, ll time) {
  ll sum = 0;
  for (int i = 0; i < b; ++i) {
    sum +=  time / m[i] + 1;
  }
  return sum;
}

int SolveFast(int b, int n, const vi& m) {
  ll low = 0;
  ll high = ll(n) * *min_element(m.begin(), m.end());
  while (low < high) {
    ll mid = (low + high) / 2;
    ll sum = ComputeEnteredBefore(b, m, mid);
    if (sum >= n - 1) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  ll time = low;
  ll sum_entered = ComputeEnteredBefore(b, m, time);
  if (sum_entered == n - 1) {
    ll min_inc = time;
    for (int i = 0; i < b; ++i) {
      min_inc = min(min_inc, m[i] - (time % m[i]));
    } 
    for (int i = 0; i < b; ++i) {
      if (m[i] - time % m[i] == min_inc) {
        return i + 1;
      }
    }
  } else {
    ll time_before = time - 1;
    ll sum = ComputeEnteredBefore(b, m, time_before);
    for (int i = 0; i < b; ++i) {
      if (time % m[i] == 0) {
        if (sum == n - 1) {
          return i + 1;
        }
        ++sum;
      }
    }
  }
  return -1;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int b, n;
    cin >> b >> n;
    vi m(b);
    for (int i = 0; i < b; ++i) {
      cin >> m[i];
    }
    int result = SolveFast(b, n, m);
    /*if (n <= 1000000) {
      int result2 = SolveSlow(b, n, m);
      if (result != result2) {
        cerr << result << ' ' << result2 << endl;
        abort();
      }
    }*/
    cout << "Case #" << (test_index + 1) << ": " << result << endl;
    cerr << "Case #" << (test_index + 1) << ": " << result << endl;
  }
  return 0;
}
